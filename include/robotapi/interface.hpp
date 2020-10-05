/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Interface Namespace File.
 * \details This file declares the interface namespace of the RobotAPI library.
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
				 * \namespace lis::pecase::productive40::robotapi::interface
				 * \brief Provides interfaces to manipulate the robots.
 				 * \details This namespace provides interfaces to interact with the robots.
				 */
				namespace interface {

				#pragma region Class Forward Declarations

					class RobotInterface;

					class DefaultInterface;

				#pragma endregion

				}; // namespace interface

				#pragma region Types Definitions

				/**
				 * \brief Alias for interface::RobotInterface.
				 * \details Alias for interface::RobotInterface.
				 */
				using RobotInterface = interface::RobotInterface;

				/**
				 * \brief Alias for interface::DefaultInterface.
				 * \details Alias for interface::DefaultInterface.
				 */
				using RobotInterface = interface::DefaultInterface;

				#pragma endregion

			}; // namespace robotapi

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "interface/robot_interface.hpp"
#include "interface/default_interface.hpp"