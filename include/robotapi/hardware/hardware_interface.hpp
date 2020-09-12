/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an interface for Hardware access.
 * \details This file provides an interface to access the hardware of the robot.
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
#include "robot_information.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::hardware {
	
#pragma region Types Definitions

	/**
	 * \interface HardwareInterface include/robotapi/hardware/hardware_interface.hpp \
	 * <productive40/robotapi/hardware/hardware_interface.hpp>
	 * \brief Interface to access the hardware of the robot.
	 * \details This interface provides generic access to the hardware. Subclass this
	 * interface to implement specific hardware access.
	 * \nosubgrouping
	 */
	class ROBOTAPI_LIB HardwareInterface {

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
		HardwareInterface (
			void
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public: virtual
		~HardwareInterface (
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
		 * \details Returns basic informations stored in the robot.
		 * \returns (const hardware::RobotInformation &) Informations about the robot.
		 */
		 public: virtual
		 const RobotInformation &
		 robot_informations (
			void
		 ) const = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class HardwareInterface

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::hardware

/*
===================================================================================================
    Macros
===================================================================================================
*/