/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file implements the default controller.
 * \details This file implements the default controller proposed in Mellah et al, 4-mecanum wheeled
 * mobile robot actuator fault detection & isolation using unknown input observer-based approach,
 * 2020.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../include/robotapi/controller/default_controller.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::controller {
	
#pragma region Constructors / Destructor
	
	DefaultController::DefaultController (
		 const hardware::HardwareInterface & hw_interface
	) :
		m_robotInformations(hw_interface.robot_informations()) {
	}

	DefaultController::~DefaultController (
		void
	) {
	}

#pragma endregion

#pragma region Robot Manipulation

	const hardware::RobotInformation &
	DefaultController::robot_informations (
		void
	) const {
		return this->m_robotInformations;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::controller