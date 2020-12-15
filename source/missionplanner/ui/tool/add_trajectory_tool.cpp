/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the add trajectory tool.
 * \details This file implements the main window of the add trajectory tool.
 */

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/globals.hpp"
#include "../../../../include/missionplanner/ui/tool/add_trajectory_tool.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::tool {

#pragma region Constructors / Destructor

	AddTrajectoryTool::AddTrajectoryTool (
		 widget::MissionScene * mission_scene
	) :
		widget::MissionScene::MissionSceneTool(mission_scene) {
	}

	AddTrajectoryTool::~AddTrajectoryTool (
		void
	) {
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Scene Manipulations

	void
	AddTrajectoryTool::enable (
		void
	) {
		this->m_missionScene->setNormalEventProcessing(false);
	}

	void
	AddTrajectoryTool::disable (
		void
	) {
	}

	void
	AddTrajectoryTool::leftMousePressed (
		qreal x,
		qreal y
	) {
		this->m_missionScene->createTrajectoryPoint(x, y);
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::tool