/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Controller Namespace File.
 * \details This file declares the Communication namespace of the RobotAPI library.
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
				 * \namespace lis::pecase::productive40::robotapi::communication
				 * \brief Contains the code related to the communication namespace.
 				 * \details This namespace provides implementations of the communication
				 * components.
				 */
				namespace communication {

				#pragma region Types Forward Declarations

					class ROBOTAPI_LIB CommunicationInterface;

				#pragma endregion

				}; // namespace communication

			}; // namespace robotapi

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "communication/communication_interface.hpp"

/*
===================================================================================================
    Macros
===================================================================================================
*/