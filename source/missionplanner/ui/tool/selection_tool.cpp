/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the selection tool.
 * \details This file implements the main window of the selection tool.
 */

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/globals.hpp"
#include "../../../../include/missionplanner/ui/tool/selection_tool.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::tool {

#pragma region Constructors / Destructor

	SelectionTool::SelectionTool (
		 widget::MissionScene * mission_scene
	) :
		widget::MissionScene::MissionSceneTool(mission_scene) {
	}

	SelectionTool::~SelectionTool (
		void
	) {
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Scene Manipulations

	void
	SelectionTool::enable (
		void
	) {
		this->m_missionScene->setNormalEventProcessing(true);
		this->m_missionScene->setTrajectorySelectability(false);
		this->m_missionScene->setRobotSelectability(true);
	}

	void
	SelectionTool::disable (
		void
	) {
		this->m_missionScene->setNormalEventProcessing(false);
	}

	void
	SelectionTool::leftMousePressed (
		qreal x,
		qreal y
	) {
		QList<QGraphicsItem *> selected_robots = this->m_missionScene->selectedItems();
		QList<const robot::RobotModel *> robots;
		for(auto r : selected_robots) {
			robots.append(&((widget::RobotWidget *)r)->robotModel());
		}
		emit this->m_missionScene->selectedRobots(robots, this->m_missionScene);
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::tool