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
				inline
				char const * const
				Workspace_Name_ = "PRODUCTIVE 4.0";

				/**
				 * \brief Major Version of the workspace.
				 * \details Major Version of the workspace.
				 */
				inline
				const uint8
				Workspace_Version_Major_ = 1;

				/**
				 * \brief Minor Version of the workspace.
				 * \details Minor Version of the workspace.
				 */
				inline
				const uint8
				Workspace_Version_Minor_ = 0;

				/**
				 * \brief Version of the workspace.
				 * \details Version of the workspace.
				 */
				inline
				const uint16
				Worspace_Version = (Workspace_Version_Minor_ << 8) + Workspace_Version_Major_;

			#pragma endregion

			}; // namespace constants

		#pragma region Constants Definitions

			/**
			 * \brief Alias for workspace name.
			 * \details Alias for workspace name.
			 */
			inline
			char const * const
			Workspace_Name = constants::Workspace_Name;

			/**
			 * \brief Alias for workspace version.
			 * \details Alias for workspace version.
			 */
			inline
			const uint8 &
			Workspace_Version = constants::Worspace_Version;

			/**
			 * \brief Alias for workspace major version.
			 * \details Alias for workspace major version.
			 */
			inline
			const uint8 &
			Workspace_Version_Major = constants::Worspace_Version_Major;

			/**
			 * \brief Alias for workspace minor version.
			 * \details Alias for workspace minor version.
			 */
			inline
			const uint8 &
			Workspace_Version_Minor = constants::Worspace_Version_Minor;

		#pragma endregion
			
		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis