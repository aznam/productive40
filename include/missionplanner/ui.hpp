/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief UI Namespace File.
 * \details This file declares the UI namespace of the mission planner.
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
				 * \namespace lis::pecase::productive40::missionplanner::ui
				 * \brief Contains the code related to the user interface of the mission planner.
				 * \details Contains the code related to the user interface of the mission planner.
				 */
				namespace ui {

				#pragma region Forward Declarations

					class MainWindow;

					class LoggerWindow;

					class InspectorWindow;

				#pragma endregion

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
#include "ui/widget.hpp"
#include "ui/tool.hpp"
#include "ui/main_window.hpp"
#include "ui/logger_window.hpp"
#include "ui/inspector_window.hpp"