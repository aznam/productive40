#include "../../../../include/missionplanner/ui/widget/mission_scene.hpp"

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsSceneMouseEvent>

namespace lis::pecase::productive40::missionplanner::ui::widget {

	MissionScene::MissionScene (
		qreal x,
		qreal y,
		qreal width,
		qreal height,
		QObject * parent
	) :
		QGraphicsScene (x, y, width, height, parent) {
	}

	MissionScene::~MissionScene (
		void
	) {
	}

	QGraphicsEllipseItem *
	MissionScene::createTrajectoryPoint (
			double x,
			double y
	) {
		QGraphicsEllipseItem * item = this->addEllipse(x, y, 16, 16);
		this->m_trajectoryPointItem.push_back(item);

		return item;
	}

	RobotWidget *
	MissionScene::createRobotWidget (
		const std::string & name
	) {
		QString robot_name = QString::fromStdString(name);
		auto robot_exists = this->m_robotWidgets.find(robot_name);
		if(robot_exists != this->m_robotWidgets.end()) {
			return robot_exists->second;
		}
		RobotWidget * robot_widget = new RobotWidget(name);
		this->addItem(robot_widget);
		this->m_robotWidgets[robot_name] = robot_widget;
		return robot_widget;
	}

	RobotWidget *
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
	MissionScene::mousePressEvent (
		QGraphicsSceneMouseEvent * mouse_event
	) {
		if(mouse_event->button() == Qt::LeftButton) {
			QGraphicsScene::mousePressEvent(mouse_event);
			if(this->selectedItems().size() == 0) {
				QPointF coords = mouse_event->lastScenePos();
				this->createTrajectoryPoint(coords.x(), coords.y());
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
	}

};