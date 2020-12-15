/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the robot element.
 * \details This file implements the main window of the robot list item widget.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/ui/widget/robot_element.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::widget {

#pragma region Constructors / Destructor

	RobotElement::RobotElement (
		const robot::RobotModel & robot_model
	) :
		QListWidgetItem(QString::fromStdString(robot_model._identifier)),
		m_robotModel((robot::RobotModel &) robot_model) {
	}

	RobotElement::~RobotElement (
		void
	) {
	}

#pragma endregion

#pragma region Methods Definitions and Implementations

	#pragma region Robot Model Accesors (Getters)

	const robot::RobotModel &
	RobotElement::robotModel(
		void
	) {
		return this->m_robotModel;
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::widget