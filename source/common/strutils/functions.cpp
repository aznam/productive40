/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Implementations of string manipulations functions.
 * \details This file implements the functions to help string manipulations.
 */

/*
===================================================================================================
	Module
===================================================================================================
*/

/*
===================================================================================================
    Standard Includes
===================================================================================================
*/
#include <sstream>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../include/common/strutils/functions.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::strutils::functions {

#pragma region Functions Definitions & Implementations

	#pragma region String Content Conversions

	void
	hextoa (
		std::string hex_str,
		byte * arr
	) {
		if(hex_str.length() % 2 != 0) {
			hex_str.append("0");
		}
		size_t len = hex_str.length() / 2;
		for(size_t i = 0; i < len; i++) {
			sscanf(hex_str.c_str()+(2*i), "%2hhX", arr + i);
		}
	}

	std::string
	atohex (
		const byte * array,
		size_t size
	) {
		std::string hex_str;
		for(size_t sz = 0; sz < size; sz++) {
			char buf[3];
			sprintf(buf, "%02hhx", *(array + sz));
			hex_str.append(buf);
		}
		return hex_str;
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::common::strutils::functions