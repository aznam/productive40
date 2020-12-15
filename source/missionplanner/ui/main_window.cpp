/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the main window.
 * \details This file implements the main window of the mission planner.
 */

/*
===================================================================================================
    Standard Includes
===================================================================================================
*/
#include <iostream>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../include/missionplanner/globals.hpp"
#include "../../../include/missionplanner/ui/main_window.hpp"
#include "../../../include/missionplanner/ui/tool.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui {

#pragma region Constructors / Destructor

    MainWindow::MainWindow (
        QWidget * parent
    ) :
		QMainWindow(parent),
		m_missionScene(this),
		m_inspectorWindow(this),
		m_loggerWindow(this) {
        this->m_internalUITemplate.setupUi(this);

		// Scene
		this->m_internalUITemplate._mainGraphicsView->setScene(&this->m_missionScene);
		QObject::connect(
			&this->m_missionScene,
			&widget::MissionScene::selectedRobots,
			this,
			&MainWindow::selectRobots
		);

		this->m_missionScene.addTool(
			widget::MissionScene::Tool::SELECTION,
			new tool::SelectionTool(&this->m_missionScene)
		);

		this->m_missionScene.addTool(
			widget::MissionScene::Tool::TRAJADD,
			new tool::AddTrajectoryTool(&this->m_missionScene)
		);

		this->m_missionScene.addTool(
			widget::MissionScene::Tool::TRAJREM,
			new tool::RemTrajectoryTool(&this->m_missionScene)
		);

		this->m_missionScene.activateTool(widget::MissionScene::Tool::SELECTION);

		// Toolbox
		QObject::connect(
			this->m_internalUITemplate._robotToolsGroup,
			&QButtonGroup::idToggled,
			this,
			[=] (int idx, bool checked) {
				if(checked) this->m_missionScene.activateTool(std::abs(idx)-2);
			}
		);

		// Logger
		this->addDockWidget(Qt::BottomDockWidgetArea, &this->m_loggerWindow);

	#if !defined(_DEBUG)

		this->m_loggerWindow.close();

	#endif

		// Inspector
		this->addDockWidget(Qt::RightDockWidgetArea, &this->m_inspectorWindow);
		QObject::connect(
			&this->m_inspectorWindow,
			&InspectorWindow::selectedRobots,
			this,
			&MainWindow::selectRobots
		);

	#if !defined(_DEBUG)

		this->m_inspectorWindow.close();

	#endif

		// Connect Main Menu actions
		QObject::connect(
			this->m_internalUITemplate._actionFileExit,
			&QAction::triggered,
			this,
			[=] () { emit this->exitApplication(0); }
		);

		QObject::connect(
			this->m_internalUITemplate._actionDisplayLoggerOutput,
			&QAction::triggered,
			this,
			&MainWindow::displayLoggerOutput
		);

		QObject::connect(
			this->m_internalUITemplate._actionDisplayRobotInspector,
			&QAction::triggered,
			this,
			&MainWindow::displayInspector
		);

		QObject::connect (
			&this->m_inspectorWindow,
			&InspectorWindow::sendCommand,
			&this->m_missionScene,
			&widget::MissionScene::sendCommand
		);
    }

    MainWindow::~MainWindow (
        void
    ) {
		QObject::disconnect(this->m_internalUITemplate._actionFileExit);
		QObject::disconnect(this->m_internalUITemplate._actionDisplayLoggerOutput);
		QObject::disconnect(this->m_internalUITemplate._actionDisplayRobotInspector);
		QObject::disconnect(&this->m_missionScene);
		QObject::disconnect(&this->m_inspectorWindow);
		QObject::disconnect(this);
    }

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Main Menu Actions

	void
	MainWindow::displayLoggerOutput (
		void
	) {
		this->m_loggerWindow.show();
	}

	void
	MainWindow::displayInspector (
		void
	) {
		this->m_inspectorWindow.show();
	}

	#pragma endregion

	#pragma region Robot-related Events

	void
	MainWindow::selectRobots (
		const QList<const robot::RobotModel *> & robots,
		QObject * signal
	) {
		if(signal != &this->m_missionScene) this->m_missionScene.selectRobots(robots);
		if(signal != &this->m_inspectorWindow) this->m_inspectorWindow.selectRobots(robots);

		bool has_selection = robots.size() > 0;
		this->m_internalUITemplate._mainToolboxTrajectoryButton->setEnabled(has_selection);
		this->m_internalUITemplate._mainToolboxCancelTrajectoryButton->setEnabled(has_selection);

		if(this->m_internalUITemplate._robotToolsGroup->checkedButton()->isEnabled() == false) {
			this->m_internalUITemplate._mainToolboxSelectButton->setChecked(true);
		}
	}

	void
	MainWindow::displayRobot (
		const robot::RobotModel & robot_model
	) {
		this->m_missionScene.addRobot(robot_model);
		this->m_inspectorWindow.addRobot(robot_model);
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui