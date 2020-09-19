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
		unsigned int id
	) :
		QThread(parent),
		m_identifier(id) {
	}

	Simubot::~Simubot (
		void
	) {
	}

#pragma endregion

#pragma region Thread Operations

	void
	Simubot::run (
		void
	) {
		QThread::run();
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application