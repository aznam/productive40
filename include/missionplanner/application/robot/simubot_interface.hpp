/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an interface to interact with simubot.
 * \details This file provides an interface to interact with simubot.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Standard Includes
===================================================================================================
*/
#include <memory>

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtCore/QObject>

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <robotapi/interface/robot_interface.hpp>
#include <robotapi/controller.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "hardware_simulation.hpp"
#include "fake_communication.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {
	
#pragma region Types Definitions

	/**
	 * \class SimubotInterface include/missionplanner/robot/simubot_interface.hpp \
	 * <productive40/missionplanner/robot/simubot_interface.hpp>
	 * \brief Interface to interact with a simubot.
	 * \details The following interface provides access and model a simulated robot in the
	 * mission planner.
	 * \nosubgrouping
	 */
	class SimubotInterface :
		public QObject,
		public robotapi::interface::RobotInterface {

		Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Fake Communication Interface.
		 * \details Fake Communication Interface.
		 */
		private:
		FakeCommunication
		m_communication;
		
		/**
		 * \brief Simulated Hardware Interface.
		 * \details Simulated Hardware Interface.
		 */
		private:
		HardwareSimulation
		m_hardware;

		/**
		 * \brief Default Controller.
		 * \details Default Controller.
		 */
		private:
		robotapi::controller::DefaultController
		m_controller;

	/**@}*/
	#pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Construtors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default ctor.
		 * \param[in] identifier (int) Identifier of the robot.
		 */
		public:
		SimubotInterface (
			unsigned int
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~SimubotInterface (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Accessors (Getters)
	 */
	#pragma region Accessors (Getters)
	/**@{*/

		#pragma region Implemented Methods

		/**
		 * \brief Access to the communication subsystem.
		 * \details Access to the communication subsystem.
		 * \return (CommunicationSystem *) Pointer to the communication subsystem.
		 */
		public:
		robotapi::communication::CommunicationInterface *
		communication (
			void
		) const override;

		/**
		 * \brief Access to the controller interface.
		 * \details Access to the controller interface.
		 * \return (ControllerInterface *) Pointer to the controller interface.
		 */
		public:
		robotapi::controller::ControllerInterface *
		controller ( 
			void
		) const override;

		/**
		 * \brief Access to the hardware interface.
		 * \details Access to the hardware interface.
		 * \return (HardwareInterface *) Pointer to the hardware interface.
		 */
		public:
		robotapi::hardware::HardwareInterface *
		hardware (
			void
		) const override;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot Operations.
	 */
	#pragma region Robot Operations
	/**@{*/

		#pragma region Slots

		/**
		 * \brief Update the robot.
		 * \details Update the robot.
		 */
		public slots:
		void
		update (
			void
		) override;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class SimubotInterface

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot