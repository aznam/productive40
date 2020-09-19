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
	Project Includes
===================================================================================================
*/
#include <robotapi/robot_interface.hpp>
#include <robotapi/controller.hpp>
#include "hardware_simulation.hpp"

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
		public robotapi::RobotInterface {

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

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
		 */
		public:
		SimubotInterface (
			void
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

	/**@}*/
	#pragma endregion

	}; // class SimubotInterface

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot