/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Controller Namespace File.
 * \details This file declares the Controller namespace of the RobotAPI library.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "robotapi_defines.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis {
	
	namespace pecase {

		namespace productive40 {

			namespace robotapi {

				/**
				 * \namespace lis::pecase::productive40::robotapi::controller
				 * \brief Contains the code related to the controller namespace.
 				 * \details This namespace provides implementations of the controller components.
				 */
				namespace controller {

				#pragma region Types Forward Declarations

					class ROBOTAPI_LIB ControllerInterface;

					class ROBOTAPI_LIB DefaultController;

				#pragma endregion

				}; // namespace controller

			}; // namespace robotapi

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "controller/controller_interface.hpp"
#include "controller/default_controller.hpp"

/*
===================================================================================================
    Macros
===================================================================================================
*/