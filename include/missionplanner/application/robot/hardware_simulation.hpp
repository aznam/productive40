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

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class HardwareSimulation

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot