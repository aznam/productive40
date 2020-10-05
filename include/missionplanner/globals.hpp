/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file defines globals variables for the Mission Planner package.
 * \details This file defines globals variables for the Mission Planner package.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Workspace Includes
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

			namespace missionplanner {

				/**
				 * \namespace lis::pecase::productive40::missionplanner::globals
				 * \brief Contains globals variables.
 				 * \details Contains globals variables.
				 */
				namespace globals {

				#pragma region Global Variables Forward Declarations

					/**
					 * \brief Main Logger of the application.
					 * \details Main Logger of the application.
					 */
					extern
					common::logging::Logger
					logger_;

				#pragma endregion

				}; // namespace globals

			#pragma region Variables Alias

				/**
				 * \brief Alias for the main logger.
				 * \details Alias for the main logger.
				 */
				static
				common::logging::Logger &
				logger_ = globals::logger_;

			#pragma endregion

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis