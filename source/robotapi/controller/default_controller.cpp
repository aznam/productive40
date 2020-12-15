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
#include <iostream>
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
		m_hardware((hardware::HardwareInterface &)(hw_interface)),
		m_elapsedTime(0.0) {
		this->m_destination = this->m_hardware.position();
		this->m_source = this->m_destination;
		this->addState(new IdleState(*this));
		this->addState(new PrepareState(*this));
		this->addState(new AccelState(*this));
		this->addState(new CruiseState(*this));
		this->addState(new DeccelState(*this));

		// Change state to idle
		this->changeState(StateIdentifier::IDLE);
	}

	DefaultController::~DefaultController (
		void
	) {
	}

	DefaultController::BaseState::BaseState (
		DefaultController & controller
	) :
		DefaultController::State(controller),
		m_maxDuration(std::numeric_limits<double>::max()) {
		this->m_start = std::make_tuple(0.0, 0.0, 0.0);
		this->m_end = std::make_tuple(0.0, 0.0, 0.0);
	}

	DefaultController::BaseState::~BaseState (
		void
	) {
	}

	DefaultController::IdleState::IdleState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

	DefaultController::IdleState::~IdleState (
		void
	) {
	}

	DefaultController::PrepareState::PrepareState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
		this->m_maxDuration = 0.0;
	}

	DefaultController::PrepareState::~PrepareState (
		void
	) {
	}

	DefaultController::AccelState::AccelState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

	DefaultController::AccelState::~AccelState (
		void
	) {
	}

	DefaultController::CruiseState::CruiseState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

	DefaultController::CruiseState::~CruiseState (
		void
	) {
	}

	DefaultController::DeccelState::DeccelState (
		DefaultController & controller
	) :
		DefaultController::BaseState(controller) {
	}

	DefaultController::DeccelState::~DeccelState (
		void
	) {
	}

#pragma endregion

#pragma region State Operations

	void
	DefaultController::IdleState::enter (
		void
	) {
		std::cout << "Enter idle state" << std::endl;

		std::vector<double> wheel_commands;
		for(unsigned i = 0; i < 4; i++)
			wheel_commands.push_back(0.0);
		this->m_context.m_hardware.wheelCommand(wheel_commands);
		this->m_context.m_elapsedTime = 0.0;
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
		std::cout << "Enter prepare state" << std::endl;
		this->m_context.m_elapsedTime = 0.0;
		if(this->m_context.m_trajectoryPoints.empty()) {
			this->m_context.changeState(StateIdentifier::IDLE); // Idle
		}
		else {
			this->m_context.computeTrajectoryProfile(
				this->m_context.m_hardware.position(), // or last destination
				this->m_context.m_trajectoryPoints.back()
			);
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
		if(!this->m_context.m_trajectoryPoints.empty()) {
			this->m_context.m_trajectoryPoints.pop_back();
		}
	}

	void
	DefaultController::AccelState::enter (
		void
	) {
		std::cout << "Enter accel state after " << this->m_context.m_elapsedTime/1000 << std::endl;
	}

	void
	DefaultController::AccelState::update (
		void
	) {
		double t = this->m_context.m_elapsedTime / 1000.0;

		double t0 = std::get<0>(this->m_start);
		double v0 = std::get<1>(this->m_start);
		double p0 = std::get<2>(this->m_start);

		double at, vt, pt;
		double dt = (t - t0);

		at = this->m_context.robotInformations()._maxLinearAccel;
		vt = at*dt + v0;
		pt = (0.5*at*dt*dt) + v0*dt + p0;

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
		std::cout << "Enter cruise state after " << this->m_context.m_elapsedTime / 1000 << std::endl;
	}

	void
	DefaultController::CruiseState::update (
		void
	) {
		double t = this->m_context.m_elapsedTime / 1000.0;

		double t0 = std::get<0>(this->m_start);
		double v0 = std::get<1>(this->m_start);
		double p0 = std::get<2>(this->m_start);

		double at, vt, pt;
		double dt = (t - t0);

		at = 0.0;
		vt = v0;
		pt = v0*dt + p0;

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
		std::cout << "Enter deccel state after " << this->m_context.m_elapsedTime / 1000 << std::endl;
	}

	void
	DefaultController::DeccelState::update (
		void
	) {
		double t = this->m_context.m_elapsedTime / 1000.0;

		double t0 = std::get<0>(this->m_start);
		double v0 = std::get<1>(this->m_start);
		double p0 = std::get<2>(this->m_start);

		double at, vt, pt;
		double dt = (t - t0);

		at = -this->m_context.robotInformations()._maxLinearAccel;
		vt = at * dt + v0;
		pt = (0.5 * at * dt * dt) + v0 * dt + p0;

		this->computeCommand(at, vt, pt);
	}

	void
	DefaultController::DeccelState::exit (
		void
	) {
		// Nothing to do
	}

#pragma endregion

#pragma region Time Management

	void
	DefaultController::BaseState::setMaxDuration (
		double max_duration
	) {
		this->m_maxDuration = max_duration * 1000;
	}

	double
	DefaultController::BaseState::getMaxDuration (
		void
	) const {
		return this->m_maxDuration;
	}

	void
	DefaultController::BaseState::setStartState (
		double t,
		double v,
		double p
	) {
		this->m_start = std::make_tuple(t, v, p);
	}

	void
	DefaultController::BaseState::setEndState (
		double t,
		double v,
		double p
	) {
		this->m_end = std::make_tuple(t, v, p);
	}

#pragma endregion

#pragma region Command Operations

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

		Eigen::MatrixXd betaTheta = this->m_context.m_hardware.orientationMatrix(
			this->m_context.targetOrientation()
		);

		// Compute the pseudo-inverse of B_theta
		Eigen::MatrixXd beta_theta_inv =
			betaTheta.completeOrthogonalDecomposition().pseudoInverse();


		Eigen::Matrix3d y_measured, y_reference;
		y_measured(0, 0) = this->m_context.m_hardware.acceleration().x();
		y_measured(1, 0) = this->m_context.m_hardware.acceleration().y();
		y_measured(2, 0) = this->m_context.m_hardware.angularAcceleration();
		y_measured(0, 1) = this->m_context.m_hardware.velocity().x();
		y_measured(1, 1) = this->m_context.m_hardware.velocity().y();
		y_measured(2, 1) = this->m_context.m_hardware.angularSpeed();
		y_measured(0, 2) = this->m_context.m_hardware.position().x();
		y_measured(1, 2) = this->m_context.m_hardware.position().y();
		y_measured(2, 2) = this->m_context.m_hardware.orientation();

		y_reference(0, 0) = at * cos(this->m_context.targetOrientation());
		y_reference(1, 0) = at * sin(this->m_context.targetOrientation());
		y_reference(2, 0) = 0.0;
		y_reference(0, 1) = vt * cos(this->m_context.targetOrientation());
		y_reference(1, 1) = vt * sin(this->m_context.targetOrientation());
		y_reference(2, 1) = 0.0;
		y_reference(0, 2) = (pt * cos(this->m_context.targetOrientation())) + this->m_context.m_source.x();
		y_reference(1, 2) = (pt * sin(this->m_context.targetOrientation())) + this->m_context.m_source.y();
		y_reference(2, 2) = this->m_context.targetOrientation();

		Eigen::Matrix3d y_diff = y_reference - y_measured;
		Eigen::Vector3d v;
		v(0, 0) = (a3 * y_diff(0, 2)) + (a2 * y_diff(0, 1)) + (a1 * y_reference(0, 0));
		v(1, 0) = (a3 * y_diff(1, 2)) + (a2 * y_diff(1, 1)) + (a1 * y_reference(1, 0));
		v(2, 0) = (a3 * y_diff(2, 2)) + (a2 * y_diff(2, 1)) + (a1 * y_reference(2, 0));

		Eigen::Vector4d wheelCommand = beta_theta_inv * v;
		std::vector<double> command;
		for(unsigned i = 0; i < 4; i++)
			command.push_back(wheelCommand(i));
		this->m_context.m_hardware.wheelCommand(command);
	}

#pragma endregion

#pragma region Robot Manipulation & Handling

	void
	DefaultController::stateCheck (
		double t
	) {
		if(this->m_currentState == nullptr || this->m_nextState != nullptr) return;

		if(this->m_currentState != this->m_states[StateIdentifier::IDLE]) {
			this->m_elapsedTime += t;
			if(this->m_elapsedTime >= ((BaseState *)this->m_currentState)->getMaxDuration()) {
				this->m_nextState = this->m_statesStack.top();
				this->m_statesStack.pop();
			}
		}
	}

	void
	DefaultController::update (
		double t
	) {
		this->stateCheck(t);
		this->GenericFSM<DefaultController>::update();
	}

	void
	DefaultController::startTravel (
		void
	) {
		this->changeState(StateIdentifier::PREPARE);
	}

	void
	DefaultController::stopTravel (
		void
	) {
		this->changeState(StateIdentifier::IDLE);
	}

	const hardware::RobotInformation &
	DefaultController::robotInformations (
		void
	) const {
		return this->m_hardware.robotInformations();
	}

#pragma endregion

#pragma region Trajectory Management

	void
	DefaultController::computeTrajectoryProfile (
		const Eigen::Vector2d & initial_point,
		const Eigen::Vector2d & final_point
	) {
		static const double epsilon = 1e-8;

		this->m_source = initial_point;
		this->m_destination = final_point;

		double vrec = this->robotInformations()._maxLinearSpeed;
		double macc = this->robotInformations()._maxLinearAccel;

		// Step 1 : compute the distance di
		double dist = (this->m_destination - this->m_source).norm();

		std::cout << "============================" << std::endl;
		std::cout << "Submission distance : " << dist << std::endl;

		// Step 2 : compute the time need for acceleration and decelerration
		double dt_acc = vrec / macc;

		std::cout << "Accel/Decel step (time) : " << dt_acc << std::endl;

		// Step 3 : compute the distance covered during acceleration and decelerration
		double dist_acc = 0.5*macc*dt_acc*dt_acc;

		std::cout << "Accel/Decel step (distance) : " << dist_acc << std::endl;

		// Step 4 : compute the distance to cover at constant speed
		double dist_crs = dist - (2 * dist_acc);

		if(dist_crs > epsilon) { // There is a cruise distance
			// Step 5 : compute the time spent at constant speed
			double dt_crs = dist_crs / vrec;

			std::cout << "Cruise (time) : " << dt_crs << std::endl;
			std::cout << "Cruise step (distance) : " << dist_crs << std::endl;
			std::cout << "============================" << std::endl << std::endl;

			this->m_statesStack.push((BaseState *)this->m_states[StateIdentifier::PREPARE]);
			this->m_statesStack.push((BaseState *)this->m_states[StateIdentifier::DECCEL]);
			this->m_statesStack.push((BaseState *)this->m_states[StateIdentifier::CRUISE]);
			this->m_statesStack.push((BaseState *)this->m_states[StateIdentifier::ACCEL]);

			// Acceleration phase
			((BaseState *)this->m_states[StateIdentifier::ACCEL])->setMaxDuration(dt_acc);
			((BaseState *)this->m_states[StateIdentifier::ACCEL])->setStartState(
				0.0,
				0.0,
				0.0
			);

			((BaseState *)this->m_states[StateIdentifier::ACCEL])->setEndState(
				dt_acc,
				vrec,
				dist_acc
			);

			// Cruise phase
			((BaseState *)this->m_states[StateIdentifier::CRUISE])->setMaxDuration(dt_acc+dt_crs);
			((BaseState *)this->m_states[StateIdentifier::CRUISE])->setStartState(
				dt_acc,
				vrec,
				dist_acc
			);

			((BaseState *)this->m_states[StateIdentifier::CRUISE])->setEndState(
				dt_acc+dt_crs,
				vrec,
				dist_acc+dist_crs
			);

			// Deccel phase
			((BaseState *)this->m_states[StateIdentifier::DECCEL])->setMaxDuration(dt_acc*2+dt_crs);
			((BaseState *)this->m_states[StateIdentifier::DECCEL])->setStartState(
				dt_acc + dt_crs,
				vrec,
				dist_acc + dist_crs
			);

			((BaseState *)this->m_states[StateIdentifier::DECCEL])->setEndState(
				dt_acc*2+dt_crs,
				0.0,
				dist
			);

		}
		else { // There is an accel then an immediate deccel
			double dt_crs = 0.0;

			this->m_statesStack.push((BaseState *)this->m_states[StateIdentifier::PREPARE]);
			this->m_statesStack.push((BaseState *)this->m_states[StateIdentifier::DECCEL]);
			this->m_statesStack.push((BaseState *)this->m_states[StateIdentifier::ACCEL]);

			vrec = sqrt(dist / macc);

			// Acceleration phase
			((BaseState *)this->m_states[StateIdentifier::ACCEL])->setMaxDuration(dt_acc);
			((BaseState *)this->m_states[StateIdentifier::ACCEL])->setStartState(
				0.0,
				0.0,
				0.0
			);
			((BaseState *)this->m_states[StateIdentifier::ACCEL])->setEndState(
				dt_acc,
				vrec,
				dist_acc
			);

			// Deccel phase
			((BaseState *)this->m_states[StateIdentifier::DECCEL])->setMaxDuration(dt_acc*2);
			((BaseState *)this->m_states[StateIdentifier::DECCEL])->setStartState(
				dt_acc,
				vrec,
				dist_acc
			);
			((BaseState *)this->m_states[StateIdentifier::DECCEL])->setEndState(
				dt_acc * 2,
				0.0,
				dist
			);

		}
	}

	void
	DefaultController::setTrajectory (
		const std::vector<Eigen::Vector2d> & points
	) {
		for(int i = points.size()-1; i >= 0; i--) {
			this->m_trajectoryPoints.push_back(points[i]);
		}
	}

	double
	DefaultController::targetOrientation (
		void
	) const {
		double theta = this->m_hardware.orientation();

		if(this->m_currentState != nullptr &&
			this->m_currentState != this->m_states[StateIdentifier::IDLE]) {
			Eigen::RowVector2d dir =
				(this->m_destination - this->m_hardware.position()).normalized();
			if(dir.x() < 0) {
				theta = atan(dir.y() / dir.x()) + EIGEN_PI;
			}
			else {
				theta = atan(dir.y() / dir.x());
			}
		}

		return theta;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::controller