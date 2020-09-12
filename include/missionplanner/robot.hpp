/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Robot Namespace File.
 * \details This file declares the Robot namespace of the mission planner.
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
				 * \namespace lis::pecase::productive40::missionplanner::robot
				 * \brief Contains the code related to the simulated robots.
				 * \details Contains the code related to the simulated robots.
				 */
				namespace robot {

				#pragma region Forward Declarations

					class HardwareSimulation;

					class SimubotInterface;

				#pragma endregion

				}; //namespace robot

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "robot/hardware_simulation.hpp"
#include "robot/simubot_interface.hpp"

/*
===================================================================================================
    Macros
===================================================================================================
*/