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
		const char * vendor_name,
		unsigned int identifier,
		const double (& dimensions) [3],
		double mass,
		double max_linear_speed,
		double max_linear_accel,
		double inertia_moment
	) :
		_vendorName(vendor_name),
		_identifier(identifier),
		_dimensions{dimensions[0], dimensions[1], dimensions[2]},
		_mass(mass),
		_maxLinearSpeed(max_linear_speed),
		_maxLinearAccel(max_linear_accel),
		_inertiaMoment(inertia_moment) {
	}

	RobotInformation::RobotInformation (
		const RobotInformation & robot_informations
	) :
		_vendorName(robot_informations._vendorName),
		_identifier(robot_informations._identifier),
		_dimensions{
			robot_informations._dimensions[0],
			robot_informations._dimensions[1],
			robot_informations._dimensions[2],
		},
		_mass(robot_informations._mass),
		_maxLinearSpeed(robot_informations._maxLinearSpeed),
		_maxLinearAccel(robot_informations._maxLinearAccel),
		_inertiaMoment(robot_informations._inertiaMoment) {
	}

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::hardware