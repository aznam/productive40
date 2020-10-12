/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Workspace types header.
 * \details This file contains the definitions of types used in all the projects.
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

			/**
			 * \namespace lis::pecase::productive40::types
			 * \brief Contains the definitions of types used in all the projects.
			 * \details Contains the definitions of types used in all the projects.
			 */
			namespace types {

			#pragma region Types Definitions

				/**
				 * \brief 8-bits type (unsigned).
				 * \details 8-bits type (unsigned).
				 */
				typedef unsigned char uint8;

				/**
				 * \brief 8-bits type (signed).
				 * \details 8-bits type (signed).
				 */
				typedef signed char sint8;

				/**
				 * \brief 16-bits type (unsigned).
				 * \details 16-bits type (unsigned).
				 */
				typedef unsigned short uint16;

				/**
				 * \brief 16-bits type (signed).
				 * \details 16-bits type (signed).
				 */
				typedef signed short sint16;

				/**
				 * \brief 32-bits type (unsigned).
				 * \details 32-bits type (unsigned).
				 */
				typedef unsigned long uint32;

				/**
				 * \brief 32-bits type (signed).
				 * \details 32-bits type (signed).
				 */
				typedef signed long sint32;

				/**
				 * \brief 64-bits type (unsigned).
				 * \details 64-bits type (unsigned).
				 */
				typedef unsigned long long uint64;

				/**
				 * \brief 64-bits type (signed).
				 * \details 64-bits type (signed).
				 */
				typedef signed long long sint64;

			#pragma endregion

			}; // namespace types

		#pragma region Types Definitions

			/**
			 * \typedef lis::pecase::productive40::byte
			 * \brief Alias for 8-bits unsigned type.
			 * \details Alias for 8-bits unsigned type.
			 */
			using byte = types::uint8;

			/**
			 * \typedef lis::pecase::productive40::byte
			 * \brief Alias for 16-bits signed type.
			 * \details Alias for 16-bits signed type.
			 */
			using int16 = types::sint16;

			/**
			 * \typedef lis::pecase::productive40::byte
			 * \brief Alias for 32-bits signed type.
			 * \details Alias for 32-bits signed type.
			 */
			using int32 = types::sint32;

			/**
			 * \typedef lis::pecase::productive40::byte
			 * \brief Alias for 64-bits signed type.
			 * \details Alias for 64-bits signed type.
			 */
			using int64 = types::sint64;

			/**
			 * \typedef lis::pecase::productive40::byte
			 * \brief Alias for 16-bits unsigned type.
			 * \details Alias for 16-bits unsigned type.
			 */
			using uint16 = types::uint16;

			/**
			 * \typedef lis::pecase::productive40::byte
			 * \brief Alias for 32-bits unsigned type.
			 * \details Alias for 32-bits unsigned type.
			 */
			using uint32 = types::uint32;

			/**
			 * \typedef lis::pecase::productive40::byte
			 * \brief Alias for 64-bits unsigned type.
			 * \details Alias for 64-bits unsigned type.
			 */
			using uint64 = types::uint64;

		#pragma endregion
			
		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis