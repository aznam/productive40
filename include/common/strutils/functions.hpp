/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This files declares string manipulation helpers.
 * \details This file declares helpers for string manipulations.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Standard Includes
===================================================================================================
*/
#include <string>

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <types.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis {
	
	namespace pecase {

		namespace productive40 {

			namespace common {

				namespace strutils {

					/**
					 * \namespace lis::pecase::productive40::common::strutils::functions
					 * \brief This namespace contains functions for string manipulations.
					 * \details This namespace contains functions for string manipulations.
					 */
					namespace functions {

					#pragma region Functions Forward Declarations

						#pragma region String Content Conversions

						/**
						 * \brief Converts a hex string to an array of bytes.
						 * \details Converts a hex string to an array of bytes.
						 * \param[in] hex_str (std::string) The string to convert.
						 * \param[out] arr (byte *) A pointer to an array of bytes.
						 * \note The output array must have been preallocated.
						 */
						void
						hextoa (
							std::string,
							byte *
						);

						/**
						 * \brief Converts an array of bytes to an hex string.
						 * \details Converts an array of bytes to an hex string
						 * \param[in] array (const byte *) The array of bytes.
						 * \param[in] size (size_t) Size of the array.
						 * \returns (std::string) A string which contains the hex value.
						 */
						std::string
						atohex (
							const byte *,
							size_t
						);

						#pragma endregion

					#pragma endregion

					}; // namespace functions

					#pragma region Functions Aliases

					/**
					 * \brief Alias for hextoa function.
					 * \details Alias for hextoa function.
					 */
					static
					void (* const hextoa)(std::string, byte *) = functions::hextoa;

					/**
					 * \brief Alias for atohex function.
					 * \details Alias for atohex function.
					 */
					static
					std::string (* const atohex)(const byte *, size_t) = functions::atohex;

					#pragma endregion

				}; // namespace strutils

			}; // namespace common

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis