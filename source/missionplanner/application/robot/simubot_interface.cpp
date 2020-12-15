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
	Qt Includes
===================================================================================================
*/
#include <QtCore/QElapsedTimer>
#include <QtCore/QThread>

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <types.hpp>
#include <common/strutils.hpp>
#include <rosproxy/rosmanager.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/globals.hpp"
#include "../../../../include/missionplanner/application/robot/simubot_interface.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {
	
#pragma region Constructors / Destructor
	
	SimubotInterface::SimubotInterface (
		unsigned int identifier
	) :
		QObject(),
		robotapi::interface::RobotInterface(),
		m_hardware(QString::asprintf("resource/hardware/%d.xml", identifier)),
		m_controller(m_hardware),
		m_communication(this) {
		m_communication.listen(
			common::strutils::atohex(
				(byte*)this->m_hardware.robotInformations()._identifier,
				sizeof(this->m_hardware.robotInformations()._identifier)
			)
		);
	}

	SimubotInterface::~SimubotInterface (
		void
	) {
		this->disconnect();
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Accessors (Getters)

	robotapi::communication::CommunicationInterface *
	SimubotInterface::communication (
		void
	) const {
		return (robotapi::communication::CommunicationInterface *)(&this->m_communication);
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

	#pragma region Robot Operations

	void
	SimubotInterface::update (
		void
	) {
		thread_local QElapsedTimer elapsed_time;

		// Get the elapsed time since the last call
		types::uint64_t elapsed = (elapsed_time.isValid() ? elapsed_time.elapsed() : 0);

		// Update the controller
		this->controller()->update(elapsed);

		// Simulate the updating hardware
		this->hardware()->update(elapsed, this->controller()->targetOrientation());

		// Measure the refresh rate
		elapsed_time.restart();
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot