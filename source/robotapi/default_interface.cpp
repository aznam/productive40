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
#include "../../include/robotapi.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi {
	
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

#pragma region Communication Operations

	void
	DefaultInterface::broadcastIdentifier (
		void
	) {
		unsigned char buffer[robotapi::Packet_Size];
		memset(buffer, 0, robotapi::Packet_Size);
		buffer[0] = (unsigned char) MessageCode::Discovery;
		memcpy(
			(void *)(buffer + 1),
			&this->hardware()->robot_informations()._identifier,
			sizeof(this->hardware()->robot_informations()._identifier)
		);
		this->communication()->broadcast(buffer, robotapi::Packet_Size);
	}

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi