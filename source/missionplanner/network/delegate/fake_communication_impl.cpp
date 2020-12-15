/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an implementation allowing fake communication with simulation robots.
 * \details This file implements a system allowing fake communication with simulation robots.
 */

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <common/strutils.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/globals.hpp"
#include "../../../../include/missionplanner/network/delegate/fake_communication_impl.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::network::delegate {
	
#pragma region Constructors / Destructor
	
	FakeCommunicationImpl::FakeCommunicationImpl (
		void
	) :
		network::NetworkManagerImpl() {
		QObject::connect(
			virtual_network_,
			&environment::VirtualNetwork::dataReadyRead,
			this,
			[=] () { emit broadcastMessageReceived(*this); }
		);
	}

	FakeCommunicationImpl::~FakeCommunicationImpl (
		void
	) {
		/*for(auto i = m_clients.begin(); i != m_clients.end(); i++) {
			i->second->disconnectFromServer();
			delete i->second;
		}*/
	}

#pragma endregion

#pragma region Methods Definitions and Implementations

	#pragma region Broadcast Handler

	void
	FakeCommunicationImpl::readFromBroadcast (
		unsigned char * message,
		size_t & size
	) {
		virtual_network_->readData(message, size);
	}

	#pragma endregion

	#pragma region Client Management

	/*void
	FakeCommunicationImpl::connectToRobot (
		const unsigned char * address
	) {
		std::string addr_str = common::strutils::atohex(address, 16);
		if(this->m_clients.find(addr_str) == this->m_clients.end()) {
			QLocalSocket* socket = new QLocalSocket();
			this->m_clients[addr_str] = socket;

			connect(
				socket,
				&QLocalSocket::connected,
				this,
				[=] () { this->robotConnected(socket, addr_str); }
			);

			connect(
				socket,
				&QLocalSocket::disconnected,
				this,
				[=] () { this->robotDisconnected(socket, addr_str); }
			);

			/*connect(
				socket,
				&QLocalSocket::errorOccurred,
				this,
				[=] () { this->clientError(socket, addr_str); }
			);*/

			/*socket->connectToServer(QString::fromStdString(addr_str));
		}
	}

	void
	FakeCommunicationImpl::recvFromRobot (
		const std::string & client,
		unsigned char * buffer,
		size_t & size
	) {
		auto socket = this->m_clients.find(client);
		if(socket != this->m_clients.end()) {
			socket->second->read((char *)buffer, size);
		}
	}

	void
	FakeCommunicationImpl::sendToRobot (
		const std::string & client,
		unsigned char * buffer,
		size_t & size
	) {
		auto socket = this->m_clients.find(client);
		if(socket != this->m_clients.end()) {
			socket->second->write((char *)buffer, size);
		}
	}

	void
	FakeCommunicationImpl::robotConnected (
		QLocalSocket * socket,
		std::string address
	) {
		connect(
			socket,
			&QLocalSocket::readyRead,
			this,
			[=] () { emit robotMessageReceived(*this, address); }
		);
	}

	void
	FakeCommunicationImpl::robotDisconnected (
		QLocalSocket * socket,
		std::string address
	) {
		socket->close();
		this->m_clients.erase(address);
		delete socket;
	}*/

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::network::delegate