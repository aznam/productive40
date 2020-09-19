/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an implementation of the Hardware Simulated Interface.
 * \details This file provides an implementation of the Hardware Simulated Interface.
 */

/*
===================================================================================================
	Standard Includes
===================================================================================================
*/
#include <cstdlib>
#include <ctime>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/application/robot/hardware_simulation.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {
	
#pragma region Constructors / Destructor

	HardwareSimulation::HardwareSimulation (
		void
	) :
		robotapi::hardware::HardwareInterface() {
	}

	HardwareSimulation::~HardwareSimulation (
		void
	) {
	}

#pragma endregion

#pragma region Robot Information Management

	const robotapi::hardware::RobotInformation &
	HardwareSimulation::robot_informations (
		void
	) const {
		srand(time(NULL));
		static const char* vendor = "LIS";
		static robotapi::hardware::RobotInformation robot_infos(
			vendor,
			rand() % 100,
			{1.78, 0.56, 0.365},
			390.0,
			5.0,
			5.0,
			0.89
		);

		return robot_infos;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot