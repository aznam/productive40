/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Robot Namespace File.
 * \details This file declares the robot namespace of the Mission Planner.
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
				 * \brief Contains the code related to the robot management.
				 * \details Contains the code related to the robot management.
				 */
				namespace robot {

				#pragma region Forward Declarations

					class RobotInterface;

					class Robot;

					class RobotManager;

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
#include "robot/robot_interface.hpp"
#include "robot/robot.hpp"
#include "robot/robot_manager.hpp"