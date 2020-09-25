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
	Project Include
===================================================================================================
*/
#include <common/logging.hpp>

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

			#pragma region Forward Declarations

				/**
				 * \brief Console logger.
				 * \details Console logger.
				 */
				extern
				common::logging::Logger
				console_log_;

			#pragma endregion

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "missionplanner/application.hpp"
#include "missionplanner/network.hpp"
#include "missionplanner/ui.hpp"
#include "missionplanner/robot.hpp"
#include "missionplanner/environment.hpp"