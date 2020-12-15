/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Defines header for RobotAPI Lib.
 * \details The file contains the definitions of import/export macros and generic macros for
 * the "Robot API" library project.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

#if defined(WIN32) || defined(WIN64)

	#ifdef USE_ROBOTAPI

		#define ROBOTAPI_LIB __declspec(dllimport)

	#else

		#define ROBOTAPI_LIB __declspec(dllexport)

	#endif

#else

	#define ROBOTAPI_LIB

#endif