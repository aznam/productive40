/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Singleton Implementation.
 * \details This file provides an implementation for singletons.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "singleton.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::pattern {

#pragma region Singleton Management

	template <
		typename Class
	> Class &
	Singleton<Class>::instance (
		void
	) {
		static Class instance;
		return instance;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::common::pattern