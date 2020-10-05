/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Hardware Namespace File.
 * \details This file declares the hardware namespace of the RobotAPI library.
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
				 * \namespace lis::pecase::productive40::robotapi::hardware
				 * \brief Contains the code related to the hardware namespace.
 				 * \details This namespace provides implementations of the hardware components.
				 */
				namespace hardware {

				#pragma region Types Forward Declarations

					struct RobotInformation;

					class HardwareInterface;

				#pragma endregion

				}; // namespace hardware

			}; // namespace robotapi

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "hardware/robot_information.hpp"
#include "hardware/hardware_interface.hpp"