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

			namespace common {

			#pragma region Forward Declarations

				// Forward declare types, global variables, functions...

			#pragma endregion

			}; // namespace common

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "common/strutils.hpp"
#include "common/math.hpp"
#include "common/pattern.hpp"
#include "common/logging.hpp"