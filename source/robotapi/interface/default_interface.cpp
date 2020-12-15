/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an implementation of a default interface for the robot.
 * \details This file provides an implementation of a default interface for the robot.
 */

/*
===================================================================================================
	Standard Includes
===================================================================================================
*/
#include <memory>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../include/robotapi/interface/default_interface.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::interface {
	
#pragma region Constructors / Destructor
	
	DefaultInterface::DefaultInterface (
		void
	) :
		RobotInterface() {
	}

	DefaultInterface::~DefaultInterface (
		void
	) {
	}

#pragma endregion

#pragma region Methods Definitions and Implementations

	#pragma region Communication Operations

	/*void
	DefaultInterface::broadcastIdentifier (
		void
	) {
		unsigned char buffer[communication::Packet_Size];
		memset(buffer, 0, communication::Packet_Size);
		buffer[0] = (unsigned char) communication::MessageCode::Discovery;
		memcpy(
			(void *)(buffer + 1),
			&this->hardware()->robot_informations()._identifier,
			sizeof(this->hardware()->robot_informations()._identifier)
		);
		this->communication()->broadcast(buffer, communication::Packet_Size);
	}

	void
	DefaultInterface::sendWelcome (
		void
	) {
		unsigned char buffer[communication::Packet_Size];
		memset(buffer, 0, communication::Packet_Size);
		buffer[0] = (unsigned char)communication::MessageCode::Welcome;
		memcpy(
			(void *)(buffer + 1),
			&this->hardware()->robot_informations()._identifier,
			sizeof(this->hardware()->robot_informations()._identifier)
		);
		this->communication()->send(buffer, communication::Packet_Size);
	}

	void
	DefaultInterface::sendInformations (
		void
	) {
		unsigned char buffer[communication::Packet_Size];
		memset(buffer, 0, communication::Packet_Size);
		buffer[0] = (unsigned char)communication::MessageCode::Informations;
		memcpy(
			(void *)(buffer + 1),
			&this->hardware()->robot_informations(),
			sizeof(this->hardware()->robot_informations())
		);
		this->communication()->send(buffer, communication::Packet_Size);
	}*/

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::interface