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
#include <sstream>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../include/missionplanner/globals.hpp"
#include "../../../include/missionplanner/application/simubot.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace logging = lis::pecase::productive40::common::logging;

namespace lis::pecase::productive40::missionplanner::application {

#pragma region Static Attributes Initializations

	const
	unsigned long
	Simubot::CPU_Frequency_ = 30;

#pragma endregion

#pragma region Constructors / Destructor

	Simubot::Simubot (
		QObject * parent,
		unsigned int identifier
	) :
		QThread(),
		m_refreshTimer(),
		m_robotInterface(identifier) {
		this->m_robotInterface.moveToThread(this);
		this->m_refreshTimer.moveToThread(this);
	}

	Simubot::~Simubot (
		void
	) {
		QObject::disconnect(this);
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Thread Operations

	void
	Simubot::run (
		void
	) {

	#ifdef _DEBUG

		std::ostringstream oss;
		oss << "0x" << std::hex << this;

		logger_.lock();
		logger_ << "Run Simubot Thread : " << oss.str() << common::logging::Logger::endl;
		logger_.unlock();

	#endif

		QObject::connect(
			&this->m_refreshTimer,
			&QTimer::timeout,
			&this->m_robotInterface,
			&robot::SimubotInterface::update
		);
		this->m_refreshTimer.start(Simubot::CPU_Frequency_);

		QThread::run();

		this->m_refreshTimer.stop();
		QObject::disconnect(
			&this->m_refreshTimer,
			nullptr,
			&this->m_robotInterface,
			nullptr
		);
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application