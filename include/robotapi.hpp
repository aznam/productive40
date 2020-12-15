/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief RobotAPI Library Project Main Include File.
 * \details The project "Robot API" provides an interface to manage a robot. It implements
 * control, diagnostic and pronostics algorithms. This library is designed to be integrated into
 * a robot subsystem and doesn't provide low-level implementation of hardware and thread.
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
			 * \namespace lis::pecase::productive40::robotapi
			 * \brief Contains the code related to the RobotAPI library.
 			 * \details Contains the code related to the RobotAPI library.
			 */
			namespace robotapi {

			}; // namespace robotapi

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Package Includes
===================================================================================================
*/
#include "robotapi/robotapi_defines.hpp"
#include "robotapi/interface.hpp"
#include "robotapi/communication.hpp"
#include "robotapi/hardware.hpp"
#include "robotapi/controller.hpp"