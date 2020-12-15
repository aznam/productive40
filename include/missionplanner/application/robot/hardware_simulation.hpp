/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an interface for simulated hardware.
 * \details This file provides an interface for simulated hardware.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QString>

/*
===================================================================================================
    Workspace Includes
===================================================================================================
*/
#include <robotapi/hardware.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {

#pragma region Types Definitions

	/**
	 * \class HardwareSimulation include/missionplanner/application/robot/hardware_simulation.hpp \
	 * <productive40/missionplanner/application/robot/hardware_simulation.hpp>
	 * \brief Hardware Simulated Interface.
	 * \details This class implements an access to simulated hardware in the mission planner.
	 * It is used for the simulation of the hardware part of the robot, in order to test the
	 * algorithms directly in the mission planner without ROS.
	 * \nosubgrouping
	 */
    class HardwareSimulation :
		public robotapi::hardware::HardwareInterface {

	/**
	 * \name Constants
	 */
	#pragma region Constants
	/**@{*/

		/**
		 * \brief Matrix A1.
		 * \details Matrix A1.
		 */
		private: static const
		Eigen::Matrix<double, 6, 6>
		MatrixA1_;

		/**
		 * \brief Matrix A2.
		 * \details Matrix A2.
		 */
		private: static const
		Eigen::Matrix<double, 6, 6>
		MatrixA2_;

		/**
		 * \brief Matrix C.
		 * \details Matrix C.
		 */
		private: static const
		Eigen::Matrix<double, 4, 6>
		MatrixC_;

	/**@}*/
	#pragma endregion

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Informations concerning the hardware.
		 * \details Informations concerning the hardware.
		 */
		private:
		robotapi::hardware::RobotInformation
		m_informations;

		/**
		 * \brief Y Vector.
		 * \details [x, y, theta, theta_prime].
		 */
		private:
		Eigen::Vector4d
		m_Y;

		/**
		 * \brief X Dot.
		 * \details [x_prime, y_prime, theta_prime, x_second, y_second, theta_second]
		 */
		private:
		Eigen::Matrix<double, 6, 1>
		m_Xdot;

		/**
		 * \brief Wheel command.
		 * \details Wheel command.
		 */
		private:
		Eigen::Vector4d
		m_wheelCommands;

	/**@}*/
	#pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Constructors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 * \param[in] config_file (QString) Name of the config file describing the hardware.
		 */
		public:
		HardwareSimulation (
			QString
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~HardwareSimulation (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot Information Management
	 */
	#pragma region Robot Information Management
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Load a simulated hardware from a config file.
		 * \details Load a simulated hardware from a config file.
		 * \param[in] filename (const QString &) Config filename.
		 */
		private:
		void
		loadFromFile (
			const QString &
		);

		#pragma endregion

		#pragma region Implemented Methods

		/**
		 * \brief Returns basic informations about the robot.
		 * \details Returns basic informations stored in the robot.
		 * \returns (const hardware::RobotInformation &) Informations about the robot.
		 */
		public:
		const robotapi::hardware::RobotInformation &
		robotInformations (
		void
		) const override;

		/**
		 * \brief Returns the position of the robot.
		 * \details Returns the position of the robot.
		 * \returns (Eigen::Vector2d) Position of the robot.
		 */
		public:
		Eigen::Vector2d
		position (
			void
		) const override;

		/**
		 * \brief Returns the orientation of the robot.
		 * \details Returns the orientation of the robot.
		 * \returns (double) Orientation of the robot (in radians).
		 */
		public:
		double
		orientation (
			void
		) const override;

		/**
		 * \brief Returns orientation matrix (Matrix B).
		 * \details Returns orientation matrix (Matrix B).
		 * \param[in] theta (double) Orientation angle.
		 * \returns (Eigen::MatrixXd) Orientation matrix.
		 */
		public:
		Eigen::MatrixXd
		orientationMatrix (
			double
		) const override;

		/**
		 * \brief Returns the velocity of the robot.
		 * \details Returns the velocity of the robot.
		 * \returns (Eigen::Vector2d) Velocity vector.
		 */
		public:
		Eigen::Vector2d
		velocity (
			void
		) const override;

		/**
		 * \brief Returns the angular speed.
		 * \details Returns the angular speed of the robot.
		 * \returns (double) Angular speed (in radians.s-1).
		 */
		public:
		double
		angularSpeed (
			void
		) const override;

		/**
		 * \brief Returns the acceleration of the robot.
		 * \details Returns the acceleration of the robot.
		 * \returns (Eigen::Vector2d) Acceleration vector.
		 */
		public:
		Eigen::Vector2d
		acceleration (
			void
		) const override;

		/**
		 * \brief Returns the angular acceleration.
		 * \details Returns the angular acceleration of the robot.
		 * \returns (double) Angular acceleration (in radians.s-2).
		 */
		public:
		double
		angularAcceleration (
			void
		) const override;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Harware Managements
	 */
	#pragma region Hardware Management
	/**@{*/

		#pragma region Abstract Methods

		/**
		 * \brief Send a command to the robot.
		 * \details Send a wheel command to control the robot.
		 * \param[in] command (const std::vector<double> &) List of command.
		 */
		public:
		void
		wheelCommand (
			const std::vector<double> &
		) override;

		/**
		 * \brief Update method.
		 * \details Update method.
		 * \param[in] t (double) Time since last update.
		 * \param[in] theta (double) Desired orientation.
		 */
		public:
		void
		update (
			double,
			double
		) override;

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class HardwareSimulation

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot