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
    Project Includes
===================================================================================================
*/
#include <robotapi/hardware.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::robot {

#pragma region Types Definitions

	/**
	 * \class HardwareSimulation include/missionplanner/robot/hardware_simulation.hpp \
	 * <productive40/missionplanner/robot/hardware_simulation.hpp>
	 * \brief Hardware Simulated Interface.
	 * \details This class implements an access to simulated hardware in the mission planner.
	 * It is used for the simulation of the hardware part of the robot, in order to test the
	 * algorithms directly in the mission planner without ROS.
	 * \nosubgrouping
	 */
    class HardwareSimulation :
		public robotapi::hardware::HardwareInterface {

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Constructors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 */
		public:
		HardwareSimulation (
			void
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

}; // namespace lis::pecase::productive40::missionplanner::robot