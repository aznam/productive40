/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Tool Namespace File.
 * \details This file declares the UI tool namespace of the mission planner.
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

				namespace ui {

					/**
					 * \namespace lis::pecase::productive40::missionplanner::ui::tool
					 * \brief Contains the code related to the some customized tools
					 * for the mission planner.
					 * \details Contains the code related to the some customized tools
					 * for the mission planner.
					 */
					namespace tool {

					#pragma region Forward Declarations

						class SelectionTool;

						class AddTrajectoryTool;

						class RemTrajectoryTool;

					#pragma endregion

					}; // namespace tool

				}; // namespace ui

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "tool/selection_tool.hpp"
#include "tool/add_trajectory_tool.hpp"
#include "tool/rem_trajectory_tool.hpp"