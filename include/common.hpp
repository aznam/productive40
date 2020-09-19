/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Common Library Project Main Include File.
 * \details The project "Common" is a library which gathers all the common components between
 * the projects. It contains pattern implementations, mathematical operations, etc.
 * Use this file if you need to interact with this library.
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
			 * \namespace lis::pecase::productive40::common
			 * \brief Contains the code related to the common library.
 			 * \details Contains the code related to the common library.
			 */
			namespace common {

			#pragma region Forward Declarations

				// Forward declare here global variables, constants, functions.

			#pragma endregion

			}; // namespace common

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "common/common_defines.hpp"
#include "common/math.hpp"
#include "common/pattern.hpp"

/*
===================================================================================================
    Macros
===================================================================================================
*/