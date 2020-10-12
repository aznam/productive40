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

			/**
			 * \namespace lis::pecase::productive40::constants
			 * \brief Contains the definitions of constants used in all the projects.
			 * \details Contains the definitions of constants used in all the projects.
			 */
			namespace constants {

			#pragma region Constants Definitions

				/**
				 * \brief Name of the workspace.
				 * \details Name of the workspace.
				 */
				static
				const char*
				Workspace_Name = "PRODUCTIVE 4.0";

				/**
				 * \brief Version of the workspace.
				 * \details Version of the workspace.
				 */
				static
				const unsigned short
				Worspace_Version = 10;

				/**
				 * \brief Major Version of the workspace.
				 * \details Major Version of the workspace.
				 */
				static
				const unsigned short
				Workspace_Version_Major = 1;

				/**
				 * \brief Minor Version of the workspace.
				 * \details Minor Version of the workspace.
				 */
				static
				const unsigned short
				Workspace_Version_Minor = 0;

			#pragma endregion

			}; // namespace constants

		#pragma region Constants Definitions

			/**
			 * \brief Alias for workspace name.
			 * \details Alias for workspace name.
			 */
			static
			const char*
			Workspace_Name = constants::Workspace_Name;

			/**
			 * \brief Alias for workspace version.
			 * \details Alias for workspace version.
			 */
			static
			const unsigned short &
			Workspace_Version = constants::Worspace_Version;

			/**
			 * \brief Alias for workspace major version.
			 * \details Alias for workspace major version.
			 */
			static
			const unsigned short &
			Workspace_Version_Major = constants::Worspace_Version_Major;

			/**
			 * \brief Alias for workspace minor version.
			 * \details Alias for workspace minor version.
			 */
			static
			const unsigned short &
			Workspace_Version_Minor = constants::Worspace_Version_Minor;

		#pragma endregion
			
		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis