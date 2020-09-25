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
    Project Includes
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
		 * \brief Matrix A.
		 * \details Matrix A.
		 */
		private: static const
		Eigen::Matrix<double, 6, 6>
		MatrixA_;

		/**
		 * \brief Matrix C.
		 * \details Matrix C.
		 */
		private: static const
		Eigen::Matrix<double, 4, 6>
		MatrixC_;

		/**
         * \brief
         * \details [x, y, theta, theta_prime]
         */
        private:
        Eigen::Vector4d 
        m_Y;

        /**
         * \brief
         * \details [x_prime, y_prime, theta_prime, x_second, y_second, theta_second]
         */
        private:
        Eigen::Matrix<double, 6, 1>
        m_Xdot;

		private:
		Eigen::Vector4d
		m_wheelCommands;

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		private:
		robotapi::hardware::RobotInformation
		m_informations;

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

		#pragma region Overriden Methods

		/**
		 * \brief Returns basic informations about the robot.
		 * \details Returns basic informations stored in the robot.
		 * \returns (const hardware::RobotInformation &) Informations about the robot.
		 */
		 public:
		 const robotapi::hardware::RobotInformation &
		 robot_informations (
			void
		 ) const override;

		 public: virtual
		 Eigen::Vector2d
		 position (
			void
		 ) const override;

		 public: virtual
		 double
		 orientation (
			void
		 ) const override;

		 public: virtual
		 Eigen::Vector2d
		 velocity (
			void
		 ) const override;

		 public: virtual
		 double
		 angular_speed (
			void
		 ) const override;

		 public: virtual
		 Eigen::Vector2d
		 acceleration (
			void
		 ) const override;

		 public: virtual
		 double
		 angular_acceleration (
			void
		 ) const override;

		 public: virtual
		 void
		 wheelCommand (
			const std::vector<double> &
		 ) override;

		 public: virtual
		 unsigned int
		 wheelCount (
			void
		 ) const override;

		 public: virtual
		 double
		 averageWheelRadius (
			void
		 ) const override;

		 public:
		 void
		 update (
			double
		 ) override;

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class HardwareSimulation

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot