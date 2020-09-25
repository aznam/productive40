/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the Network Manager.
 * \details This file implements the Network Manager.
 */

/*
===================================================================================================
	Standard Includes
===================================================================================================
*/
#include <iostream>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../include/missionplanner/network/network_manager.hpp"
#include <common/strutils.hpp>

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::network {

#pragma region Constructors / Destructor

	NetworkManager::NetworkManager (
		void
	) :
		common::pattern::Singleton<NetworkManager>(),
		common::pattern::Observable<NetworkInterface>(),
		m_delegates() {
		this->m_messageFunc[robotapi::communication::MessageCode::Discovery] = std::bind(
			&NetworkManager::discoveryHandler,
			this,
			std::placeholders::_1,
			std::placeholders::_2
		);
		this->m_messageFunc[robotapi::communication::MessageCode::Welcome] = std::bind(
			&NetworkManager::welcomeHandler,
			this,
			std::placeholders::_1,
			std::placeholders::_2
		);
	}

	NetworkManager::~NetworkManager (
		void
	) {
		for(unsigned t = 0; t < this->m_delegates.size(); t++) {
			delete this->m_delegates[t];
		}
	}

#pragma endregion

#pragma region Message Parsing

	void
	NetworkManager::parse (
		NetworkManagerImpl & interface,
		const unsigned char * buffer
	) {
		// Read the first byte containing the message code
		unsigned char message_code = buffer[0];

		auto iter = m_messageFunc.find((robotapi::communication::MessageCode) message_code);
		if(iter != m_messageFunc.end()) {
			(iter->second)(interface, buffer + 1);
		}
	}

	void
	NetworkManager::discoveryHandler (
		NetworkManagerImpl & interface,
		const unsigned char * buffer
	) {
		interface.connectToRobot(buffer);
	}

	void
	NetworkManager::welcomeHandler (
		NetworkManagerImpl & interface,
		const unsigned char * buffer
	) {
		std::string robot_name((const char *)buffer);
		this->notify(&NetworkInterface::robotConnected, robot_name);
	}

#pragma endregion

#pragma region Delegates Handling

	void
	NetworkManager::addNetworkDelegate (
		NetworkManagerImpl * delegate
	) {
		this->m_delegates.push_back(delegate);

		// Broadcast Events
		connect(
			delegate,
			&NetworkManagerImpl::broadcastMessageReceived,
			this,
			&NetworkManager::broadcastAvailable
		);

		// Client Events
		connect(
			delegate,
			&NetworkManagerImpl::robotMessageReceived,
			this,
			&NetworkManager::dataAvailable
		);
	}

#pragma endregion

#pragma region Client Handlers

	void
	NetworkManager::dataAvailable (
		NetworkManagerImpl & interface,
		std::string address
	) {
		unsigned char buffer[robotapi::communication::Packet_Size];
		memset(buffer, 0, robotapi::communication::Packet_Size);
		size_t size = robotapi::communication::Packet_Size;

		interface.recvFromRobot(address, buffer, size);
		this->parse(interface, buffer);
	}

#pragma endregion

#pragma region Broadcast Handlers

	void
	NetworkManager::broadcastAvailable (
		NetworkManagerImpl & interface
	) {
		unsigned char buffer[robotapi::communication::Packet_Size];
		memset(buffer, 0, robotapi::communication::Packet_Size);
		size_t size = robotapi::communication::Packet_Size;

		interface.readFromBroadcast(buffer, size);
		this->parse(interface, buffer);
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::network