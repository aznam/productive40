/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of a virtual network for mission planner.
 * \details This file implements the virtual network of the mission planner.
 */

/*
===================================================================================================
    Qt Includes
===================================================================================================
*/
#include <QMutexLocker>
#include <iostream>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../include/missionplanner/environment/virtual_network.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::environment {

#pragma region Constructors / Destructor

    VirtualNetwork::VirtualNetwork (
		void
    ) :
		QObject(nullptr) {
		this->connect(
			&this->m_environmentData,
			&QBuffer::readyRead,
			this,
			&VirtualNetwork::dataReadyRead
		);
		this->m_environmentData.open(QIODevice::ReadWrite);
    }

    VirtualNetwork::~VirtualNetwork (
        void
    ) {
		this->m_environmentData.close();
		this->disconnect(
			&this->m_environmentData,
			&QBuffer::readyRead,
			this,
			&VirtualNetwork::dataReadyRead
		);
    }

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Data Transmission

	void
	VirtualNetwork::sendData (
		const unsigned char * data,
		size_t size
	) {
		QMutexLocker lock(&this->m_dataMutex);
		this->m_environmentData.seek(this->m_environmentData.size());
		this->m_environmentData.write((char *)data, size);
	}

	void
	VirtualNetwork::readData (
		unsigned char * data,
		size_t & size
	) {
		QMutexLocker lock(&this->m_dataMutex);
		this->m_environmentData.seek(0);
		this->m_environmentData.read((char *)data, size);
		this->m_environmentData.buffer().remove(0, size);
	}

	bool
	VirtualNetwork::dataAvailable (
		void
	) {
		QMutexLocker lock(&this->m_dataMutex);
		return this->m_environmentData.bytesAvailable() > 0;
	}

	#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::environment