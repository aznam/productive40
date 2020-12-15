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
    Qt Includes
===================================================================================================
*/
#include <QtWidgets/QGraphicsSceneEvent>
#include <QtMath>


/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/ui/widget/mission_scene.hpp"
#include "../../../../include/missionplanner/globals.hpp"

#include <rosproxy/rosmanager.hpp>
#include <common/strutils.hpp>


/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::widget {

#pragma region Constructors / Destructor

	MissionScene::MissionScene (
		 QObject * parent
	) :
		QGraphicsScene(parent),
		m_currentTool(nullptr),
		m_tools{ nullptr },
		m_robotsList(),
		m_normalEventProcess(true) {

		QObject::connect (
			this,
			&QGraphicsScene::selectionChanged,
			this,
			[=] () {
				/*logger_.lock();
				logger_
					<< "[SIGNAL] Selection changed : "
					<< (uint32)this->selectedItems().count()
					<< common::logging::endl;
				logger_.unlock();*/
			}
		);

		QObject::connect(
			&this->m_timer,
			&QTimer::timeout,
			this,
			&MissionScene::refresh
		);
		this->m_timer.start(10);
	}

	void MissionScene::refresh() {
		for(auto r : this->m_robotsList) {
			const robot::RobotModel * robot = &((widget::RobotWidget *)r.second)->robotModel();
			r.second->setPos(robot->_simubot->hardware()->position().x(), robot->_simubot->hardware()->position().y());
			r.second->setRotation(qRadiansToDegrees(robot->_simubot->hardware()->orientation()));

			
		}
	}

	MissionScene::~MissionScene (
		void
	) {
		for(auto tool : this->m_tools) delete tool;
		QObject::disconnect(this);
	}

	MissionScene::MissionSceneTool::MissionSceneTool (
		MissionScene * mission_scene
	) :
		m_missionScene(mission_scene) {
	}

	MissionScene::MissionSceneTool::~MissionSceneTool (
		void
	) {
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Tools Management

	void
	MissionScene::sendCommand(
	) {
		for(auto r : this->m_robotsList) {
			if(r.second->isSelected()) {
				const robot::RobotModel * robot = &((widget::RobotWidget *)r.second)->robotModel();
				TrajectoryWidget * trajectory =
					m_trajectoriesList[robot];
				std::vector<Eigen::Vector2d> points = trajectory->toVector();
				robot->_simubot->controller()->setTrajectory(points);
				robot->_simubot->controller()->startTravel();
			}
		}
	}

	void
	MissionScene::addTool (
		Tool idx,
		MissionSceneTool *  tool
	) {
		if(this->m_tools[idx] != nullptr) delete this->m_tools[idx];
		this->m_tools[idx] = tool;
	}

	void
	MissionScene::activateTool (
		int tool_idx
	) {
		if(this->m_currentTool != nullptr) this->m_currentTool->disable();
		this->m_currentTool = (tool_idx > -1 ? this->m_tools[tool_idx] : nullptr);
		if(this->m_currentTool != nullptr) this->m_currentTool->enable();
	}

	void
	MissionScene::setNormalEventProcessing (
		bool flag
	) {
		this->m_normalEventProcess = flag;

		// Double protection :)
		for(auto r : this->m_robotsList) {
			r.second->setAcceptedMouseButtons(
				flag ? Qt::MouseButton::AllButtons : Qt::MouseButton::NoButton
			);
		}

		for(auto r : this->m_trajectoriesList) {
			r.second->setAcceptedMouseButtons(
				flag ? Qt::MouseButton::AllButtons : Qt::MouseButton::NoButton
			);
		}
	}

	void
	MissionScene::mousePressEvent (
		QGraphicsSceneMouseEvent * mouse_event
	) {
		// Because Qt decided to handle multi-selection in the release event handler
		if(
			(mouse_event->modifiers() & Qt::KeyboardModifier::ControlModifier) == 0 &&
			mouse_event->button() == Qt::LeftButton
		) {
			if(this->m_normalEventProcess) this->QGraphicsScene::mousePressEvent(mouse_event);
			if(this->m_currentTool != nullptr) {
				this->m_currentTool->leftMousePressed(
					mouse_event->scenePos().x(),
					mouse_event->scenePos().y()
				);
			}
		}
		else {
			// if(this->m_normalEventProcess) this->QGraphicsScene::mousePressEvent(mouse_event);
		}
	}

	void
	MissionScene::mouseReleaseEvent (
		QGraphicsSceneMouseEvent * mouse_event
	) {
		// Because Qt decided to handle multi-selection in the release event handler
		if(
			mouse_event->modifiers() & Qt::KeyboardModifier::ControlModifier &&
			mouse_event->button() == Qt::LeftButton
		) {
			if(this->m_normalEventProcess) this->QGraphicsScene::mouseReleaseEvent(mouse_event);
			if(this->m_currentTool != nullptr) {
				this->m_currentTool->leftMousePressed(
					mouse_event->scenePos().x(),
					mouse_event->scenePos().y()
				);
			}
		}
		else {
			if(this->m_normalEventProcess) this->QGraphicsScene::mouseReleaseEvent(mouse_event);
		}
	}

	void
	MissionScene::mouseDoubleClickEvent (
		QGraphicsSceneMouseEvent * mouse_event
	) {
		mouse_event->ignore();
	}

	#pragma endregion

	#pragma region Robot Widgets Management

	RobotWidget *
	MissionScene::addRobot (
		const robot::RobotModel & robot_model
	) {
		RobotWidget * robot_widget = new RobotWidget(robot_model);
		TrajectoryWidget* trajectory_widget = new TrajectoryWidget(robot_model);
		this->addItem(robot_widget);
		this->addItem(trajectory_widget);
		this->m_robotsList[&robot_model] = robot_widget;
		this->m_trajectoriesList[&robot_model] = trajectory_widget;
		return robot_widget;
	}

	void
	MissionScene::selectRobots (
		const QList<const robot::RobotModel *> & robots
	) {
		for(auto r : this->m_robotsList) {
			r.second->setSelected(false);
		}

		for(auto r : this->m_trajectoriesList) {
			r.second->clear();
		}

		for(auto r : robots) {
			this->m_robotsList[r]->setSelected(true);
		}
	}

	void
	MissionScene::setRobotSelectability (
		bool toggle
	) {
		for(auto r : this->m_robotsList) {
			r.second->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable, toggle);
		}
	}
	
	void
	MissionScene::createTrajectoryPoint (
			double x,
			double y
	) {
		for(auto r : this->selectedItems()) {
			const robot::RobotModel * robot = &((RobotWidget*)r)->robotModel();
			this->m_trajectoriesList[robot]->addPoint(x, y);
		}
	}

	void
	MissionScene::removeTrajectoryPoint (
		QGraphicsItem * traj_point
	) {
		traj_point->setParentItem(nullptr);
		delete traj_point;
	}

	void
	MissionScene::setTrajectorySelectability (
		bool toggle
	) {
		for(auto r : this->m_trajectoriesList) {
			r.second->toggleSelectable(toggle);
		}
	}

	/*RobotWidget *
	MissionScene::findRobotWidget (
		const QString & robot_name
	) const {
		auto robot_exists = this->m_robotWidgets.find(robot_name);
		if(robot_exists != this->m_robotWidgets.end()) {
			return robot_exists->second;
		}
		return nullptr;
	}

	void
	MissionScene::unselectAll (
		void
	) {
		for(auto iter = this->m_robotWidgets.begin(); iter != this->m_robotWidgets.end(); iter++) {
			iter->second->select(false);
		}
	}

	void MissionScene::select (
		const QList<QString> & selected
	) {
		for(auto iter = selected.begin(); iter < selected.end(); iter++) {
			this->findRobotWidget(*iter)->select(true);
		}
	}

	void MissionScene::select (
		RobotWidget * robot
	) {
		for(auto iter = this->m_robotWidgets.begin(); iter != this->m_robotWidgets.end(); iter++) {
			if(iter->second == robot) {
				robot->select(true);
				return;
			}
		}
	}

	

	void
	MissionScene::mouseReleaseEvent (
		QGraphicsSceneMouseEvent * mouse_event
	) {
		if(mouse_event->button() == Qt::RightButton && !this->m_trajectoryPointItem.empty()) {
			this->removeItem(this->m_trajectoryPointItem[this->m_trajectoryPointItem.size()-1]);
			this->m_trajectoryPointItem.pop_back();
		}
	}*/

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::widget