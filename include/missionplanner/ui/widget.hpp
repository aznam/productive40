/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Widget Namespace File.
 * \details This file declares the UI widget namespace of the mission planner.
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
					 * \namespace lis::pecase::productive40::missionplanner::ui::widget
					 * \brief Contains the code related to the some customized widgets
					 * for the mission planner.
					 * \details Contains the code related to the some customized widgets
					 * for the mission planner.
					 */
					namespace widget {

					#pragma region Forward Declarations

						class MissionScene;

						class RobotWidget;

						class RobotElement;

						class TrajectoryWidget;

					#pragma endregion

					}; // namespace widget

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
#include "widget/mission_scene.hpp"
#include "widget/robot_widget.hpp"
#include "widget/robot_element.hpp"
#include "widget/trajectory_widget.hpp"