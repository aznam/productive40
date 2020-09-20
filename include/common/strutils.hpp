/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Strutils Namespace File.
 * \details This file declares the strutils namespace of the "Common" library.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Standard includes
===================================================================================================
*/
#include <string>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis {
	
	namespace pecase {

		namespace productive40 {

			namespace common {

				/**
				 * \namespace lis::pecase::productive40::common::strutils
				 * \brief Contains the code related to the strutils namespace.
 				 * \details This namespace provides string manipulation algorithms.
				 */
				namespace strutils {

				#pragma region Functions Forward Declarations

					#pragma region Conversions

					/**
					 * \brief Converts a hex string to an array of bytes.
					 * \details Converts a hex string to an array of bytes.
					 * \param hex_str (std::string) The string to convert.
					 * \param arr (unsigned char *) A pointer to an array of bytes.
					 */
					extern
					void
					hextoa (
						std::string,
						unsigned char *
					);

					/**
					 * \brief Converts an array of bytes to an hex string.
					 * \details Converts an array of bytes to an hex string
					 * \param array (const unsigned char *) The array of bytes.
					 * \param size (size_t) Size of the array.
* 					 * \returns (std::string) A string which contains the hex value.
					 */
					extern
					std::string
					atohex (
						const unsigned char *,
						size_t
					);

					#pragma endregion

				#pragma endregion

				}; // namespace strutils

			}; // namespace common

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis