/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an implementation of the simubot interface.
 * \details This file implements the interface to interact with the simubot.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/application/robot/simubot_interface.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {
	
#pragma region Constructors / Destructor
	
	SimubotInterface::SimubotInterface (
		void
	) :
		robotapi::RobotInterface(),
		m_hardware(),
		m_controller(m_hardware) {
	}

	SimubotInterface::~SimubotInterface (
		void
	) {
	}

#pragma endregion

#pragma region Accessors (Getters)

	robotapi::communication::CommunicationInterface *
	SimubotInterface::communication (
		void
	) const {
		return nullptr;
	}

	robotapi::controller::ControllerInterface *
	SimubotInterface::controller (
		void
	) const {
		return (robotapi::controller::ControllerInterface *)(&this->m_controller);
	}

	robotapi::hardware::HardwareInterface *
	SimubotInterface::hardware (
		void
	) const {
		return (robotapi::hardware::HardwareInterface *)(&this->m_hardware);
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot