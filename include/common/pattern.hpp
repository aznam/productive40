/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Pattern Namespace File.
 * \details This file declares the Pattern namespace of the common library.
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

				/**
				 * \namespace lis::pecase::productive40::common::pattern
				 * \brief Contains the code related to the pattern namespace.
 				 * \details This namespace provides some implementations of generic patterns.
				 */
				namespace pattern {

				#pragma region Class Forward Declarations

					template<typename> class GenericFSM;

				#pragma endregion

				}; // namespace pattern

			}; // namespace common

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "pattern/generic_fsm.hpp"

/*
===================================================================================================
    Macros
===================================================================================================
*/