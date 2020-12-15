/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Mission Planner Project Main Include File.
 * \details The project "Mission Planner" provides a demo application in which the user can
 * control and make diagnostic of robots.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis {
	
	namespace pecase {

		namespace productive40 {

			/**
			 * \namespace lis::pecase::productive40::missionplanner
			 * \brief Contains the code related to the MissionPlanner.
 			 * \details Contains the code related to the MissionPlanner.
			 */
			namespace missionplanner {

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Package Includes
===================================================================================================
*/
#include "missionplanner/defines.hpp"
#include "missionplanner/globals.hpp"
#include "missionplanner/constants.hpp"
#include "missionplanner/application.hpp"
#include "missionplanner/environment.hpp"
#include "missionplanner/network.hpp"
#include "missionplanner/ui.hpp"
#include "missionplanner/robot.hpp"