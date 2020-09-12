/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an interface to interact with robot.
 * \details This file provides an interface to interact and access the robot. This interface
 * must be implemented for each kind of robot.
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
#include "robotapi_defines.hpp"
#include "controller/controller_interface.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi {
	
#pragma region Types Definitions

	/**
	 * \interface RobotInterface include/robotapi/robot_interface.hpp \
	 * <productive40/robotapi/robot_interface.hpp>
	 * \brief Interface to interact with the robot.
	 * \details The following high-level interface allows access to components and interactions
	 * with the robot. For each kind of robot, this interface must be implemented to provide an
	 * access to the different algorithm.
	 * \nosubgrouping
	 */
	class ROBOTAPI_LIB RobotInterface {

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
		protected:
		RobotInterface (
			void
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public: virtual
		~RobotInterface (
			void
		) = 0;

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
		/*public: virtual
		communication::CommunicationSystem *
		communication (
			void
		) = 0;*/

		/**
		 * \brief Access to the controller interface.
		 * \details Access to the controller interface.
		 * \return (ControllerInterface *) Pointer to the controller interface.
		 */
		public: virtual
		controller::ControllerInterface *
		controller ( 
			void
		) = 0;

		/**
		 * \brief Access to the hardware interface.
		 * \details Access to the hardware interface.
		 * \return (HardwareInterface *) Pointer to the hardware interface.
		 */
		/*public: virtual
		hardware::HardwareInterface *
		hardware (
			void
		) = 0;*/

	/**@}*/
	#pragma endregion

	}; // class RobotInterface

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi

/*
===================================================================================================
    Macros
===================================================================================================
*/