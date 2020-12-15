/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the remove trajectory tool.
 * \details This file implements the main window of the remove trajectory tool.
 */

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/globals.hpp"
#include "../../../../include/missionplanner/ui/tool/rem_trajectory_tool.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::tool {

#pragma region Constructors / Destructor

	RemTrajectoryTool::RemTrajectoryTool (
		 widget::MissionScene * mission_scene
	) :
		widget::MissionScene::MissionSceneTool(mission_scene),
		m_selectedRobots() {
	}

	RemTrajectoryTool::~RemTrajectoryTool (
		void
	) {
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Scene Manipulations

	void
	RemTrajectoryTool::enable (
		void
	) {
		this->m_missionScene->setNormalEventProcessing(true);
		this->m_selectedRobots = this->m_missionScene->selectedItems();
		this->m_missionScene->setTrajectorySelectability(true);
		this->m_missionScene->setRobotSelectability(false);
	}

	void
	RemTrajectoryTool::disable (
		void
	) {
		this->m_missionScene->setRobotSelectability(true);
		for(auto w : this->m_selectedRobots)
			w->setSelected(true);
	}

	void
	RemTrajectoryTool::leftMousePressed (
		qreal x,
		qreal y
	) {
		QList<QGraphicsItem *> selected_waypoints = this->m_missionScene->selectedItems();
		for(auto r : selected_waypoints) {
			this->m_missionScene->removeTrajectoryPoint(r);
		}
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::tool