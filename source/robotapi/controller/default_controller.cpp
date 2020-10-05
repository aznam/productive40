/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file implements the default controller.
 * \details This file implements the default controller proposed in Mellah et al, 4-mecanum wheeled
 * mobile robot actuator fault detection & isolation using unknown input observer-based approach,
 * 2020.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../include/robotapi/controller/default_controller.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::controller {
	
#pragma region Constructors / Destructor
	
	DefaultController::DefaultController (
		 const hardware::HardwareInterface & hw_interface
	) :
		m_robotInformations(hw_interface.robot_informations()),
		m_hardware((hardware::HardwareInterface &)(hw_interface)),
		m_refreshTime(0) {
		this->addState(new IdleState(*this));
		this->addState(new PrepareState(*this));
		this->addState(new AccelState(*this));
		this->addState(new CruiseState(*this));
		this->addState(new DeccelState(*this));
	}

	DefaultController::~DefaultController (
		void
	) {
	}

	DefaultController::BaseState::BaseState (
		DefaultController & controller
	) :
		DefaultController::State(controller),
		m_maxTime(std::numeric_limits<double>::max()) {
	}

	DefaultController::IdleState::IdleState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

	DefaultController::PrepareState::PrepareState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

	DefaultController::AccelState::AccelState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

	DefaultController::CruiseState::CruiseState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

	DefaultController::DeccelState::DeccelState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

#pragma endregion

	void
	DefaultController::BaseState::setMaxTime (
		double max_time
	) {
		this->m_maxTime = max_time;
	}

	void
	DefaultController::IdleState::enter (
		void
	) {
		std::vector<double> wheel_commands;
		for(unsigned i = 0; i < this->m_context.m_hardware.wheelCount(); i++)
			wheel_commands.push_back(0.0);
		this->m_context.m_hardware.wheelCommand(wheel_commands);
	}

	void
	DefaultController::IdleState::update (
		void
	) {
		// Infinite wait until we start a new trajectory
	}

	void
	DefaultController::IdleState::exit (
		void
	) {
		// Nothing to do
	}

	void
	DefaultController::PrepareState::enter (
		void
	) {
		if(this->m_context.m_trajectoryPoints.empty()) {
			this->m_context.changeState(0); // Idle
		}
		else {
			this->m_context.m_destination = this->m_context.m_trajectoryPoints.back();
			this->m_context.m_trajectoryPoints.pop_back();

			// Compute the acceleration profile
			static const double epsilon = 1e-8;

			// Store the current position in the trajectory
			Eigen::Vector2d current_position = this->m_context.m_hardware.position();
			this->m_context.m_initialPosition = current_position;

			// Step 1 : compute the distance di
			double di = (this->m_context.m_destination - current_position).norm();

			// Step 2 : compute the time need for acceleration and decelerration
			double dt1 =
				this->m_context.m_robotInformations._maxLinearSpeed /
				this->m_context.m_robotInformations._maxLinearAccel;

			// Step 3 : compute the distance covered during acceleration and decelerration
			double dist1 = dt1 * this->m_context.m_robotInformations._maxLinearSpeed;

			// Step 4 : compute the distance to cover at constant speed
			double dist2 = di - 2 * dt1;

			if(dist2 >= epsilon) { // We can achieve the mission with highest speed
				// Step 5 : compute the time spent at constant speed
				double dt2 = dist2 / this->m_context.m_robotInformations._maxLinearSpeed;

				// Set the Vmax
				this->m_context.m_profile[0] = this->m_context.m_robotInformations._maxLinearSpeed;

				this->m_context.setTimeMax(2, dt1); // Accel
				this->m_context.m_profile[1] = dt1;
				this->m_context.m_profile[2] =
					(this->m_context.m_robotInformations._maxLinearAccel * 0.5 * dt1 * dt1);

				this->m_context.setTimeMax(3, dt1+dt2); // Cruise
				this->m_context.m_profile[3] = dt1 + dt2;
				this->m_context.m_profile[4] =
					this->m_context.m_robotInformations._maxLinearSpeed * dt2 +
						this->m_context.m_profile[2];

				this->m_context.setTimeMax(4, 2*dt1+dt2); // Deccel

			}
			else { // We accel until the mid-distance, and we deccel

				double dacc = sqrt(di / this->m_context.m_robotInformations._maxLinearAccel);

				this->m_context.m_profile[0] =
					dacc * this->m_context.m_robotInformations._maxLinearAccel;
				this->m_context.m_profile[1] = dacc;
				this->m_context.m_profile[2] =
					(this->m_context.m_robotInformations._maxLinearAccel * 0.5 * dacc * dacc);
				this->m_context.m_profile[3] = 0.0;
				this->m_context.m_profile[4] = this->m_context.m_profile[2];

				this->m_context.setTimeMax(2, dacc); // Accel

				this->m_context.setTimeMax(3, dacc); // Cruise

				this->m_context.setTimeMax(4, 2*dacc); // Deccel
			}

			this->m_context.changeState(2); // Acceleration
		}
	}

	void
	DefaultController::PrepareState::update (
		void
	) {
		// Nothing to do
	}

	void
	DefaultController::PrepareState::exit (
		void
	) {
		this->m_context.m_elapsedTime = 0; // Not really here (this function may be called at a
		// random time in multithreaded time, or if execution time changes at each loop).
	}

	void
	DefaultController::AccelState::enter (
		void
	) {
		// Nothing to do
	}

	void
	DefaultController::AccelState::update (
		void
	) {
		this->m_context.m_elapsedTime += this->m_context.m_refreshTime;
		// Todo : do it in Machine Update
		if(this->m_context.m_elapsedTime > this->m_maxTime) {
			this->m_context.changeState(3); // Cruise
			return;
		}

		double t = this->m_context.m_elapsedTime / 1000.0;
		double at, vt, pt;
		at = this->m_context.m_robotInformations._maxLinearAccel;
		vt = this->m_context.m_robotInformations._maxLinearAccel * t;
		pt = this->m_context.m_robotInformations._maxLinearAccel * 0.5 * t * t;
		this->computeCommand(at, vt, pt);
	}

	void
	DefaultController::AccelState::exit (
		void
	) {
		// Nothing to do
	}

	void
	DefaultController::CruiseState::enter (
		void
	) {
		// Nothing to do
	}

	void
	DefaultController::CruiseState::update (
		void
	) {
		this->m_context.m_elapsedTime += this->m_context.m_refreshTime;
		// Todo : do it in Machine Update
		if(this->m_context.m_elapsedTime > this->m_maxTime) {
			this->m_context.changeState(4); // Deccel
			return;
		}

		double t = this->m_context.m_elapsedTime / 1000.0;
		double at, vt, pt;
		at = 0.0;
		vt = this->m_context.m_profile[0];
		pt = vt * (t - this->m_context.m_profile[1]) + this->m_context.m_profile[2];
		this->computeCommand(at, vt, pt);
	}

	void
	DefaultController::CruiseState::exit (
		void
	) {
		// Nothing to do
	}

	void
	DefaultController::DeccelState::enter (
		void
	) {
		// Nothing to do
	}

	void
	DefaultController::DeccelState::update (
		void
	) {
		this->m_context.m_elapsedTime += this->m_context.m_refreshTime;
		// Todo : do it in Machine Update
		if(this->m_context.m_elapsedTime > this->m_maxTime) {
			this->m_context.changeState(0); // Idle
			return;
		}

		double t = this->m_context.m_elapsedTime / 1000.0;
		double at, vt, pt;
		at = -this->m_context.m_robotInformations._maxLinearAccel;
		vt = -this->m_context.m_robotInformations._maxLinearAccel *
			(t- this->m_context.m_profile[3]) + this->m_context.m_profile[0];
		pt = -this->m_context.m_robotInformations._maxLinearAccel * 0.5 * t *t *
			(this->m_context.m_profile[0] - this->m_context.m_profile[3] * at) * t +
			this->m_context.m_profile[4];
		this->computeCommand(at, vt, pt);
	}

	void
	DefaultController::DeccelState::exit (
		void
	) {
		// Nothing to do
	}

	void
	DefaultController::BaseState::computeCommand (
		double at,
		double vt,
		double pt
	) {
        // Poles : [-1 -1.5]
        static const double a1 = 1;
        static const double a2 = 2.5;
        static const double a3 = 1.5;

        // Compute the direction
        double theta = this->m_context.m_hardware.orientation();
        Eigen::RowVector2d dir =
			(this->m_context.m_destination - this->m_context.m_hardware.position());
        if(dir.x() < 0) {
            theta = atan(dir.y()/dir.x())+EIGEN_PI;
        }
        else {
            theta = atan(dir.y()/dir.x());
        }
        double c = cos(theta);
        double d = sin(theta);

        // Compute B_theta
        double cpd = (c+d) / this->m_context.coeffA();
        double cmd = (c-d) / this->m_context.coeffA();
        double dmc = (d-c) / this->m_context.coeffA();
        double lb = 0.5*(
				this->m_context.m_robotInformations._dimensions[0] +
				this->m_context.m_robotInformations._dimensions[1]
			) / this->m_context.coeffB();

		Eigen::MatrixXd betaTheta(3, 4);
        betaTheta(0,0) = cmd;  
        betaTheta(0,1) = cpd;
        betaTheta(0,2) = cmd;
        betaTheta(0,3) = cpd;
        betaTheta(1,0) = cpd;  
        betaTheta(1,1) = dmc;
        betaTheta(1,2) = cpd;
        betaTheta(1,3) = dmc;
        betaTheta(2,0) = lb;  
        betaTheta(2,1) = -lb;
        betaTheta(2,2) = -lb;
        betaTheta(2,3) = lb;
                    
        // Compute the pseudo-inverse of B_theta
        Eigen::MatrixXd beta_theta_inv = 
            betaTheta.completeOrthogonalDecomposition().pseudoInverse();


        Eigen::Matrix3d y_measured, y_reference;
        y_measured(0,0) = this->m_context.m_hardware.acceleration().x();
        y_measured(1,0) = this->m_context.m_hardware.acceleration().y();
        y_measured(2,0) = this->m_context.m_hardware.angular_acceleration();
        y_measured(0,1) = this->m_context.m_hardware.velocity().x();
        y_measured(1,1) = this->m_context.m_hardware.velocity().y();
        y_measured(2,1) = this->m_context.m_hardware.angular_speed();
        y_measured(0,2) = this->m_context.m_hardware.position().x();
        y_measured(1,2) = this->m_context.m_hardware.position().y();
        y_measured(2,2) = this->m_context.m_hardware.orientation();

        /*std::cout << "Acceleration:" << at*c << " " << at*d << std::endl;
        std::cout << "Velocity:" << vt * c << " " << vt * d << std::endl;
        std::cout << "Position:" << pt * c << " " << pt * d << std::endl;*/

        y_reference(0, 0) = at*c;
        y_reference(1, 0) = at*d;
        y_reference(2, 0) = 0.0;
        y_reference(0, 1) = vt*c;
        y_reference(1, 1) = vt*d;
        y_reference(2, 1) = 0.0;
        y_reference(0, 2) = pt*c+this->m_context.m_initialPosition.x();
        y_reference(1, 2) = pt*d+this->m_context.m_initialPosition.y();
        y_reference(2, 2) = theta;

        Eigen::Matrix3d y_diff = y_reference - y_measured;
        Eigen::Vector3d v;
        v(0,0) = a3*y_diff(0,2)+a2*y_diff(0,1)+a1*y_reference(0,0);
        v(1,0) = a3*y_diff(1,2)+a2*y_diff(1,1)+a1*y_reference(1,0);
        v(2,0) = a3*y_diff(2,2)+a2*y_diff(2,1)+a1*y_reference(2,0);

		Eigen::Vector4d wheelCommand = beta_theta_inv*v;
		std::vector<double> command;
		for(unsigned i = 0; i < this->m_context.m_hardware.wheelCount(); i++)
			command.push_back(wheelCommand(i));
		this->m_context.m_hardware.wheelCommand(command);
	}

#pragma region Robot Manipulation

	const hardware::RobotInformation &
	DefaultController::robot_informations (
		void
	) const {
		return this->m_robotInformations;
	}

	void
	DefaultController::startTravel (
		void
	) {
		this->changeState(1); // Prepare State
	}

	void
	DefaultController::stopTravel (
		void
	) {
		this->changeState(0); // Idle State
	}

	void
	DefaultController::setTimeMax (
		unsigned int state_id,
		double time_max
	) {
		((BaseState*)this->m_states[state_id])->setMaxTime(time_max);
	}

	void
	DefaultController::update (
		double t
	) {
		this->m_refreshTime = t;
		// TODO : Change the state before calling update
		this->GenericFSM<DefaultController>::update();
	}

	double
	DefaultController::coeffA (
        void
    ) const {
        return(
			2.0 * this->m_hardware.robot_informations()._mass *
				this->m_hardware.averageWheelRadius()
		);
    }

    double
    DefaultController::coeffB (
        void
    ) const {
        return(
			2.0 * this->m_hardware.robot_informations()._inertiaMoment *
				this->m_hardware.averageWheelRadius()
		);
    }

	void
	DefaultController::setTrajectory (
		const std::vector<Eigen::Vector2d> & trajectory
	) {
		for(auto i = trajectory.size()-1; i >= 0; i--) {
			this->m_trajectoryPoints.push_back(trajectory[i]);
		}
	}

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::controller