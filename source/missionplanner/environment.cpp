/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the environment for mission planner.
 * \details This file implements the environment of the mission planner.
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
#include "../../include/missionplanner/environment.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner {

#pragma region Constructors / Destructor

    Environment::Environment (
		void
    ) :
		QObject(nullptr) {
		connect(
			&this->m_environmentData,
			&QBuffer::readyRead,
			this,
			&Environment::dataReadyRead
		);
		this->m_environmentData.open(QIODevice::ReadWrite);
    }

    Environment::~Environment (
        void
    ) {
		this->m_environmentData.close();
    }

#pragma endregion

#pragma region Data Transmission

	void
	Environment::sendData (
		const unsigned char * data,
		size_t size
	) {
		QMutexLocker lock(&this->m_dataMutex);
		this->m_environmentData.seek(this->m_environmentData.size());
		this->m_environmentData.write((char *)data, size);
	}

	void
	Environment::readData (
		unsigned char * data,
		size_t & size
	) {
		QMutexLocker lock(&this->m_dataMutex);
		this->m_environmentData.seek(0);
		this->m_environmentData.read((char *)data, size);
		this->m_environmentData.buffer().remove(0, size);
	}

	bool
	Environment::dataAvailable (
		void
	) {
		QMutexLocker lock(&this->m_dataMutex);
		return this->m_environmentData.bytesAvailable() > 0;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner