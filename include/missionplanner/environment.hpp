/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Application Namespace File.
 * \details This file declares the environment namespace of the Mission Planner. This namespace
 * contains elements related to the model of the environment.
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

			namespace missionplanner {

				/**
				 * \namespace lis::pecase::productive40::missionplanner::environment
				 * \brief Contains the code related to the environment in the mission planner.
				 * \details Contains the code related to the environment the mission planner.
				 */
				namespace environment {

				#pragma region Forward Declarations

					class VirtualNetwork;

				#pragma endregion

				}; //namespace environment

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "environment/virtual_network.hpp"