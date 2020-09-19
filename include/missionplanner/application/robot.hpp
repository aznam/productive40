/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Application Namespace File.
 * \details This file declares the Application::Robot namespace of the mission planner.
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

				namespace application {

					/**
					 * \namespace lis::pecase::productive40::missionplanner::application::robot
					 * \brief Contains the code related to the implementation of simulated robot.
					 * \details Contains the code related to the implementation of simulated robot.
					 */
					namespace robot {

					#pragma region Forward Declarations

						class HardwareSimulation;

						class SimubotInterface;

					#pragma endregion

					}; // namespace robot

				}; //namespace application

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