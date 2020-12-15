/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the inspector window.
 * \details This file implements the inspector window of the mission planner.
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
#include "../../../include/missionplanner/ui/inspector_window.hpp"
#include "../../../include/missionplanner/ui/widget/robot_element.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui {

#pragma region Constructors / Destructor

    InspectorWindow::InspectorWindow (
        QWidget * parent
    ) :
		QDockWidget(parent),
		m_internalUITemplate(),
		m_robotTableModel(this->m_internalUITemplate._robotTable),
		m_robotsList() {
        this->m_internalUITemplate.setupUi(this);

		this->m_internalUITemplate._robotTable->setModel(&this->m_robotTableModel);

		QObject::connect(
			this->m_internalUITemplate._robotsList,
			&QListWidget::itemSelectionChanged,
			this,
			[=] () {
				QList<QListWidgetItem *> selected_robots =
					this->m_internalUITemplate._robotsList->selectedItems();
				QList<const robot::RobotModel *> robots;
				for(auto r : selected_robots) {
					robots.append(&((widget::RobotElement *)r)->robotModel());
				}
				if(selected_robots.size() == 1) {
					this->displayRobot(*robots.at(0));
				}
				emit this->selectedRobots(robots, this);
			}
		);

		this->m_internalUITemplate._wheelBar1->setRange(0,100);
		this->m_internalUITemplate._wheelBar2->setRange(0, 100);
		this->m_internalUITemplate._wheelBar3->setRange(0, 100);
		this->m_internalUITemplate._wheelBar4->setRange(0, 100);

		QObject::connect(
			this->m_internalUITemplate._sendCommandButton,
			&QPushButton::pressed,
			this,
			&InspectorWindow::sendCommand
		);

		QObject::connect(
			&this->m_timer,
			&QTimer::timeout,
			this,
			&InspectorWindow::refresh
		);
		this->m_timer.start(10);
    }

	void InspectorWindow::refresh() {
		if(this->m_internalUITemplate._robotsList->selectedItems().size() == 1) {
			const robot::RobotModel & r  = ((widget::RobotElement*)this->m_internalUITemplate._robotsList->selectedItems().at(0))->robotModel();
		}
	}

    InspectorWindow::~InspectorWindow (
        void
    ) {
		QObject::disconnect(this->m_internalUITemplate._robotsList);
		QObject::disconnect(this);
    }

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Robots Management

	void
	InspectorWindow::addRobot (
		const robot::RobotModel & robot_model
	) {
		widget::RobotElement * robot = new widget::RobotElement(robot_model);
		this->m_internalUITemplate._robotsList->addItem(robot);
		this->m_robotsList[(robot::RobotModel *)&robot_model] = robot;
	}

	void
	InspectorWindow::displayRobot (
		const robot::RobotModel & robot
	) {

		this->m_robotTableModel.setColumnCount(2);
		this->m_robotTableModel.setRowCount(6);

		this->m_robotTableModel.setItem(0, 0, new QStandardItem("Identifier"));
		this->m_robotTableModel.setItem(
			0,
			1,
			new QStandardItem(QString::fromStdString(robot._identifier))
		);

		this->m_robotTableModel.setItem(1, 0, new QStandardItem("Vendor"));
		this->m_robotTableModel.setItem(
			1,
			1,
			new QStandardItem(QString::fromStdString(robot._vendorName))
		);

		this->m_robotTableModel.setItem(2, 0, new QStandardItem("Length"));
		this->m_robotTableModel.setItem(
			2,
			1,
			new QStandardItem(QString::number(robot._length))
		);

		this->m_robotTableModel.setItem(3, 0, new QStandardItem("Width"));
		this->m_robotTableModel.setItem(
			3,
			1,
			new QStandardItem(QString::number(robot._width))
		);

		this->m_robotTableModel.setItem(4, 0, new QStandardItem("Height"));
		this->m_robotTableModel.setItem(
			4,
			1,
			new QStandardItem(QString::number(robot._height))
		);

		this->m_robotTableModel.setItem(5, 0, new QStandardItem("Mass"));
		this->m_robotTableModel.setItem(
			5,
			1,
			new QStandardItem(QString::number(robot._mass))
		);
	}

	void
	InspectorWindow::selectRobots (
		const QList<const robot::RobotModel *> & robots
	) {
		this->m_robotTableModel.clear();

		this->m_internalUITemplate._robotsList->clearSelection();

		for(auto r : robots) {
			this->m_robotsList[r]->setSelected(true);
		}

		if(robots.size() == 1) {
			this->displayRobot(*robots.at(0));
		}

		bool has_selection = robots.size() > 0;
		this->m_internalUITemplate._sendCommandButton->setEnabled(has_selection);
		this->m_internalUITemplate._clearCommandButton->setEnabled(has_selection);
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui