/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide a default interface to interact with the robot.
 * \details This file provides a default interface with useful command to interact with the robot.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../robotapi_defines.hpp"
#include "robot_interface.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::interface {
	
#pragma region Types Definitions

	/**
	 * \class DefaultInterface include/robotapi/interface/default_interface.hpp \
	 * <productive40/robotapi/interface/default_interface.hpp>
	 * \brief Class with default function to interact with the robot.
	 * \details The abstract class implements default functionnality to interact with the robot.
	 * \nosubgrouping
	 */
	class ROBOTAPI_LIB DefaultInterface :
		public RobotInterface {

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Construtors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default ctor.
		 */
		protected:
		DefaultInterface (
			void
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		protected: virtual
		~DefaultInterface (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Communication Operations
	 */
	#pragma region Communication Operations
	/**@{*/

		/**
		 * \brief Broadcast identifier.
		 * \details Send the identifier of the robot through the network.
		 */
		/*public: virtual
		void
		broadcastIdentifier (
			void
		);

		public: virtual
		void
		sendWelcome (
			void
		);*/

		/**
		 * \brief Send robot informations to the client.
		 * \details Send robot informations to the client.
		 */
		/*public: virtual
		void
		sendInformations (
			void
		);*/

	/**@}*/
	#pragma endregion

	}; // class DefaultInterface

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::interface