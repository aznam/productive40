/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an interface for Robot Communication.
 * \details This file provides an interface to interact with the communication system.
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

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::communication {
	
#pragma region Types Definitions

	/**
	 * \interface CommunicationInterface \
	 * include/robotapi/communication/communication_interface.hpp \
	 * <productive40/robotapi/communication/communication_interface.hpp>
	 * \brief Interface to control the robot.
	 * \details This interface provides generic routines to interact with the communication
	 * system and subsystems of the robot.
	 * \nosubgrouping
	 */
	class ROBOTAPI_LIB CommunicationInterface {

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Constructors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 */
		protected:
		CommunicationInterface (
			void
		) = default;

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public: virtual
		~CommunicationInterface (
			void
		) = default;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Communication Handling
	 */
	#pragma region Communication Handling
	/**@{*/

		#pragma region Abstract Methods

		/**
		 * \brief Indicates if the robot is currently connected to a mission planner.
		 * \details Indicates if the robot is currently connected to a mission planner.
		 * \retval true The robot is corrently connected to a mission planner.
		 * \retval false The robot is currently disconnected.
		 */
		public: virtual
		bool
		connected (
			void
		) const = 0;

		/**
		 * \brief Broadast a message.
		 * \details Broadcast a message on a network or air.
		 * \param[in] message (const char *) Array of bytes to broadcast.
		 * \param[in] size (unsigned long) Size of the message.
		 */
		public: virtual
		void
		broadcast (
			const unsigned char *,
			unsigned long
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class CommunicationInterface

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::communication

/*
===================================================================================================
    Macros
===================================================================================================
*/