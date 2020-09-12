/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an interface for Robot Controller.
 * \details This file provides an interface to control the robot.
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
#include "../robotapi_defines.hpp"
#include "../hardware/robot_information.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::controller {
	
#pragma region Types Definitions

	/**
	 * \interface ControllerInterface include/robotapi/controller/controller_interface.hpp \
	 * <productive40/robotapi/controller/controller_interface.hpp>
	 * \brief Interface to control the robot.
	 * \details This interface provides generic routines to control the robot. Subclass this
	 * interface to implement control algorithms.
	 * \nosubgrouping
	 */
	class ROBOTAPI_LIB ControllerInterface {

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Constructors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 */
		protected:
		ControllerInterface (
			void
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public: virtual
		~ControllerInterface (
			void
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot Manipulation
	 */
	#pragma region Robot Manipulation
	/**@{*/

		#pragma region Abstract Methods

		/**
		 * \brief Returns basic informations about the robot.
		 * \details Returns basic informations about the robot.
		 * \returns (const hardware::RobotInformation &) Informations about the robot.
		 */
		 public: virtual
		 const hardware::RobotInformation &
		 robot_informations (
			void
		 ) const = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class ControllerInterface

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::controller

/*
===================================================================================================
    Macros
===================================================================================================
*/