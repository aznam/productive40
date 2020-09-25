/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of simulated robot.
 * \details This file implements simulated robots.
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
#include "../../../include/missionplanner/application/simubot.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application {

#pragma region Constructors / Destructor

	Simubot::Simubot (
		QObject * parent,
		unsigned int identifier
	) :
		QThread(parent),
		m_refreshTimer(this),
		m_identifier(identifier),
		m_robotInterface(identifier) {
		connect(&this->m_refreshTimer, &QTimer::timeout, this, &Simubot::refresh);
		this->m_refreshTimer.start(this->m_CPUfrequency);
	}

	Simubot::~Simubot (
		void
	) {
		this->m_refreshTimer.stop();
		disconnect(&this->m_refreshTimer, &QTimer::timeout, this, &Simubot::refresh);
	}

#pragma endregion

#pragma region Thread Operations

	void
	Simubot::run (
		void
	) {
		QThread::run();
	}

	void
	Simubot::refresh (
		void
	) {
		if(this->m_robotInterface.communication()->connected() == false)
			this->m_robotInterface.broadcastIdentifier();
		else {
			// Check if an order came from the network
			if(this->m_robotInterface.communication()->requested()) {
				//this->m_robotInterface.communication()->recv();
			}

			// Process the next computation

			// Update the controller

			// Send message
		}
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application