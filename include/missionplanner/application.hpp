/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Application Namespace File.
 * \details This file declares the application namespace of the Mission Planner. This namespace
 * contains elements related to this application architecture.
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
				 * \namespace lis::pecase::productive40::missionplanner::application
				 * \brief Contains the code related to the application of the mission planner.
				 * \details Contains the code related to the application of the mission planner.
				 */
				namespace application {

				#pragma region Forward Declarations

					class WindowLoggerImpl;
					
					class Application;

					class Simubot;

				#pragma endregion

				}; //namespace application

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "application/application.hpp"
#include "application/window_logger_impl.hpp"
#include "application/simubot.hpp"
#include "application/robot.hpp"