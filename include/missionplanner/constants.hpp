/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Workspace constants header.
 * \details This file declares some constants usable in all the projects.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Includes
===================================================================================================
*/
#include "types.hpp"

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
				 * \namespace lis::pecase::productive40::missionplanner::constants
				 * \brief Contains the definitions of constants used in missionplanner app.
				 * \details Contains the definitions of constants used in missionplanner app.
				 */
				namespace constants {

				#pragma region Constants Definitions

					/**
					 * \brief General log filenale.
					 * \details General log filename.
					 */
					static
					const char*
					Log_Filename = "logs/missionplanner.log";

				#pragma endregion

				}; // namespace constants

			#pragma region Constants Definitions

				/**
				 * \brief Alias for general log filename.
				 * \details Alias for general log filename.
				 */
				static
				const char*
				Log_Filename = constants::Log_Filename;

			#pragma endregion

			}; // namespace missionplanner
			
		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis