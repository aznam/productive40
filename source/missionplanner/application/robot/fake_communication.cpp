/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an implementation a fake communication system (for simulated robots).
 * \details This file implements a fake communication system (for simulated robots).
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/globals.hpp"
#include "../../../../include/missionplanner/application/robot/fake_communication.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {
	
#pragma region Constructors / Destructor
	
	FakeCommunication::FakeCommunication (
		QObject * parent
	) :
		QObject(parent),
		robotapi::communication::CommunicationInterface(),
		m_server(this),
		m_client(nullptr),
		m_dataAvailable(false) {
		this->m_server.setMaxPendingConnections(1);
		QObject::connect(
			&this->m_server,
			&QLocalServer::newConnection,
			this,
			&FakeCommunication::pendingClientConnection
		);
	}

	FakeCommunication::~FakeCommunication (
		void
	) {
		if(this->m_client != nullptr) {
			this->m_client->close();
			delete this->m_client;
		}
		this->m_server.close();
		QObject::disconnect(&this->m_server);
		QObject::disconnect(this);
	}

#pragma endregion

#pragma region Communication Handling

	void
	FakeCommunication::listen (
		const std::string & name
	) {
		this->m_server.listen(QString::fromStdString(name));
	}

	bool
	FakeCommunication::connected (
		void
	) const {
		return this->m_client != nullptr;
	}

	void
	FakeCommunication::broadcast (
		const unsigned char * message,
		unsigned long size
	) {
		virtual_network_->sendData(message, size);
	}

	void
	FakeCommunication::send (
		const unsigned char * message,
		unsigned long size
	) {
		if(!this->connected()) return;

		this->m_client->write((char*)message, size);
	}

	void
	FakeCommunication::recv (
		unsigned char * message,
		unsigned long size
	) {
		if(!this->connected()) return;

		this->m_client->read((char *)message, size);
		this->m_dataAvailable = this->m_client->bytesAvailable() > 0;
	}

	/*bool
	FakeCommunication::requested (
		void
	) const {
		return this->m_dataAvailable || this->m_client->bytesAvailable() > 0;
	}*/

	void
	FakeCommunication::pendingClientConnection (
		void
	) {
		this->m_client = this->m_server.nextPendingConnection();
		QObject::connect(
			this->m_client,
			&QLocalSocket::readyRead,
			this,
			&FakeCommunication::readyClientRead
		);
		QObject::connect(
			this->m_client,
			&QLocalSocket::disconnected,
			this,
			&FakeCommunication::lostClientConnection
		);
	}

	void
	FakeCommunication::lostClientConnection (
		void
	) {
		this->m_client->deleteLater();
		this->m_client = nullptr;
	}

	void
	FakeCommunication::readyClientRead (
		void
	) {
		this->m_dataAvailable = true;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot