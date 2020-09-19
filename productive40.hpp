/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Workspace Main Include File.
 * \details This file gathers all the files required to interact with the entire workspace.
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

/**
 * \namespace lis
 * \brief Main LIS namespace.
 * \details Main LIS namespace.
 */
namespace lis {
	
	/**
	 * \namespace lis::pecase
	 * \brief PECASE namespace.
	 * \details PECASE namespace.
	 */
	namespace pecase {

		/**
		 * \namespace lis::pecase::productive40
		 * \brief Contains the code related to the workspace PRODUCTIVE 4.0.
		 * \details Contains the code related to the workspace PRODUCTIVE 4.0.
		 */
		namespace productive40 {

		#pragma region Forward Declarations

			const char* Project_Name = "Productive 4.0";

			const unsigned int Version = 10;

			const unsigned int Major_Version = 1;

			const unsigned int Minor_Version = 0;

		#pragma endregion

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include <common.hpp>
#include <robotapi.hpp>
#include <missionplanner.hpp>

/*
===================================================================================================
    Macros
===================================================================================================
*/