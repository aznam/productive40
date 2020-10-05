/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file initializes globals variables for the Mission Planner package.
 * \details This file initializes globals variables for the Mission Planner package.
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
#include "../../include/missionplanner/globals.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::globals {

#pragma region Global Variables Initializations

	common::logging::Logger
	logger_;

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::globals