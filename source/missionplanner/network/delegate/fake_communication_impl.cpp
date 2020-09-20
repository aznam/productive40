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
	Project Includes
===================================================================================================
*/
#include <common/strutils.hpp>
#include "../../../../include/missionplanner/environment.hpp"
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
		connect(
			&Environment::instance(),
			&Environment::dataReadyRead,
			this,
			[=] () { emit broadcastAvailable(*this); }
		);
	}

	FakeCommunicationImpl::~FakeCommunicationImpl (
		void
	) {
		for(auto i = m_clients.begin(); i != m_clients.end(); i++) {
			i->second->disconnectFromServer();
			delete i->second;
		}
	}

#pragma endregion

#pragma region Broadcast Handler

	void
	FakeCommunicationImpl::broadcastRead (
		unsigned char * message,
		size_t & size
	) {
		Environment::instance().readData(message, size);
	}

#pragma endregion

#pragma region Client Management

	void
	FakeCommunicationImpl::connectClient (
		const unsigned char * address
	) {
		std::string addr_str = common::strutils::atohex(address, 16);
		if(this->m_clients.find(addr_str) == this->m_clients.end()) {
			QLocalSocket* socket = new QLocalSocket();
			this->m_clients[addr_str] = socket;
			socket->connectToServer(QString::fromStdString(addr_str));
		}
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::network::delegate