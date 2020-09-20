/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides representations of robot informations.
 * \details This file provides representations of basic robot informations.
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

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::hardware {
	
#pragma region Types Definitions

	/**
	 * \struct RobotInformation include/robotapi/hardware/robot_information.hpp \
	 * <productive40/robotapi/hardware/robot_information.hpp>
	 * \brief Keep the basic information about the robot.
	 * \details This structure keeps basic informations concerning the robot.
	 * \nosubgrouping
	 */
	struct ROBOTAPI_LIB RobotInformation {

	/**
	 * \name Members Attributes.
	 */
	#pragma region Members Attributes
	/**@{*/

		/**
		 * \brief Vendor name.
		 * \details Vendor name.
		 */
		const char
		_vendorName [16];

		/**
		 * \brief identifier.
		 * \details identifier.
		 */
		const unsigned char
		_identifier [16];

		/**
		 * \brief Base dimensions.
		 * \details Base dimensions [length; width; height] (in meters).
		 */
		const double
		_dimensions [3];

		/**
		 * \brief Base Mass.
		 * \details Base Mass (in kilograms).
		 */
		const double
		_mass;

		/**
		 * \brief Maximum linear speed.
		 * \details Maximum linear speed (in m.s-1).
		 */
		const double
		_maxLinearSpeed;

		/**
		 * \brief Maximum linear acceleration.
		 * \details Maximum linear acceleration (in m.s-2).
		 */
		const double
		_maxLinearAccel;

		/**
		 * \brief Moment of inertia.
		 * \details Moment of inertia (in kg.m2).
		 */
		const double
		_inertiaMoment;

	/**@}*/
	#pragma endregion

	/**
	 * \name Initializers
	 */
	#pragma region Initializers
	/**@{*/

		/**
		 * \brief Default initializer.
		 * \details Default initializer.
		 * \param[in] identifier (const unsigned char (&) [16]) Identifier of the robot.
		 * \param[in] dimensions (const double (&) [3]) Dimensions of the robot (l,w,h).
		 * \param[in] mass (double) Mass of the robot.
		 * \param[in] max_linear_speed (double) Maximum linear speed.
		 * \param[in] max_linear_accel (double) Maximum linear acceleration.
		 * \param[in] inertia_moment (double) Moment of inertia.
		 */
		RobotInformation (
			const unsigned char (&) [16],
			const double (&) [3],
			double,
			double,
			double,
			double
		);

		/**
		 * \brief Copy initializer.
		 * \details Copy initializer.
		 * \param[in] robot_informations Informations to copy.
		 */
		RobotInformation (
			const RobotInformation &
		);

	/**@}*/
	#pragma endregion

	}; // struct RobotInformation

	/**
	 * \brief Conveniant typedef for struct RobotInformation.
	 * \details Conveniant typedef for struct RobotInformation.
	 */
	typedef struct RobotInformation RobotInformation;

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::hardware

/*
===================================================================================================
    Macros
===================================================================================================
*/