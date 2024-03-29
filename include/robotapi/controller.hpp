/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Controller Namespace File.
 * \details This file declares the controller namespace of the RobotAPI library.
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

			namespace robotapi {

				/**
				 * \namespace lis::pecase::productive40::robotapi::controller
				 * \brief Contains the code related to the controller namespace.
 				 * \details This namespace provides implementations of the controller components.
				 */
				namespace controller {

				#pragma region Types Forward Declarations

					class ControllerInterface;

					class DefaultController;

				#pragma endregion

				}; // namespace controller

			}; // namespace robotapi

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "controller/controller_interface.hpp"
#include "controller/default_controller.hpp"