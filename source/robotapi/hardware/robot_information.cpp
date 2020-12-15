/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides implementations of robot informations.
 * \details This file provides implementations of basic robot informations.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../include/robotapi/hardware/robot_information.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::hardware {
	
#pragma region Initializers

	RobotInformation::RobotInformation (
		const unsigned char (& identifier) [16],
		const double (& dimensions) [3],
		double mass,
		double wheel,
		double max_linear_speed,
		double max_linear_accel,
		double inertia_moment
	) :
		_vendorName("LIS"),
		_identifier{
			identifier[0],
			identifier[1],
			identifier[2],
			identifier[3],
			identifier[4],
			identifier[5],
			identifier[6],
			identifier[7],
			identifier[8],
			identifier[9],
			identifier[10],
			identifier[11],
			identifier[12],
			identifier[13],
			identifier[14],
			identifier[15],
		},
		_dimensions{dimensions[0], dimensions[1], dimensions[2]},
		_mass(mass),
		_wheel(wheel),
		_maxLinearSpeed(max_linear_speed),
		_maxLinearAccel(max_linear_accel),
		_inertiaMoment(inertia_moment) {
	}

	RobotInformation::RobotInformation (
		const RobotInformation & robot_informations
	) :
		_vendorName("LIS"),
		_identifier{
			robot_informations._identifier[0],
			robot_informations._identifier[1],
			robot_informations._identifier[2],
			robot_informations._identifier[3],
			robot_informations._identifier[4],
			robot_informations._identifier[5],
			robot_informations._identifier[6],
			robot_informations._identifier[7],
			robot_informations._identifier[8],
			robot_informations._identifier[9],
			robot_informations._identifier[10],
			robot_informations._identifier[11],
			robot_informations._identifier[12],
			robot_informations._identifier[13],
			robot_informations._identifier[14],
			robot_informations._identifier[15],
		},
		_dimensions{
			robot_informations._dimensions[0],
			robot_informations._dimensions[1],
			robot_informations._dimensions[2],
		},
		_mass(robot_informations._mass),
		_wheel(robot_informations._wheel),
		_maxLinearSpeed(robot_informations._maxLinearSpeed),
		_maxLinearAccel(robot_informations._maxLinearAccel),
		_inertiaMoment(robot_informations._inertiaMoment) {
	}

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::hardware