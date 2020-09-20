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
	Projects Includes
===================================================================================================
*/
#include "robotapi/robotapi_defines.hpp"

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

			#pragma region Constants

				/**
				 * \brief Packet size for Data Transmission.
				 * \details Packet size for Data Transmission.
				 */
				const size_t
				Packet_Size = 128;

			#pragma endregion

			#pragma region Types Definitions

				/**
				 * \enum MessageCode
				 * \brief Discovery Message Code.
				 * \details Discovery Message Code.
				 */
				enum ROBOTAPI_LIB MessageCode {

					/**
					 * \brief Discovery Code.
					 * \details Discovery Code.
					 */
					Discovery = 0x01

				};

			#pragma region

			#pragma region Forward Declarations

				class ROBOTAPI_LIB RobotInterface;

				class ROBOTAPI_LIB DefaultInterface;

			#pragma endregion

			}; // namespace robotapi

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "robotapi/hardware.hpp"
#include "robotapi/controller.hpp"
#include "robotapi/communication.hpp"
#include "robotapi/robot_interface.hpp"
#include "robotapi/default_interface.hpp"

/*
===================================================================================================
    Macros
===================================================================================================
*/