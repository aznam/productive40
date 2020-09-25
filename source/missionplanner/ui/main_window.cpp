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
#include "../../../include/missionplanner/ui/main_window.hpp"

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
		NetworkInterface() {
        this->m_internalUI.setupUi(this);
		this->m_missionScene = new widget::MissionScene(
			0,
			0,
			870,
			620,
			this->m_internalUI._grphvwPlanner
		);
		this->m_internalUI._grphvwPlanner->setScene(this->m_missionScene);
		connect(
			this->m_internalUI._robotsList,
			&QListWidget::itemSelectionChanged,
			this,
			&MainWindow::robotsSelectedFromList
		);

		connect(
			this->m_missionScene,
			&QGraphicsScene::focusItemChanged,
			this,
			&MainWindow::robotsSelectedFromScene
		);
    }

    MainWindow::~MainWindow (
        void
    ) {
    }

#pragma endregion

	void
	MainWindow::robotConnected (
		const common::pattern::Observable<NetworkInterface> & notifier,
		std::string robot_name
	) {
		this->m_internalUI._robotsList->addItem(QString::fromStdString(robot_name));
		widget::RobotWidget * robot_widget = this->m_missionScene->createRobotWidget(robot_name);
	}

	void
	MainWindow::robotDisconnected (
		const common::pattern::Observable<NetworkInterface> & notifier,
		std::string robot_name
	) {
		QList<QListWidgetItem *> items = this->m_internalUI._robotsList->findItems(
			QString::fromStdString(robot_name),
			Qt::MatchExactly
		);
		for(auto iter = items.begin(); iter < items.end(); iter++) {
			this->m_internalUI._robotsList->removeItemWidget(*iter);
		}
	}

	void
	MainWindow::robotsSelectedFromList (
		void
	) {
		QList<QListWidgetItem *> selected = this->m_internalUI._robotsList->selectedItems();
		this->m_missionScene->unselectAll();
		if(selected.size() > 0) {
			QList<QString> selected_labels;
			for(auto iter = selected.begin(); iter < selected.end(); iter++) {
				selected_labels.push_back((*iter)->text());
			}
			this->m_missionScene->select(selected_labels);

			if(selected.size() == 1) {
				this->m_internalUI._grphvwPlanner->centerOn(
					this->m_missionScene->findRobotWidget(selected[0]->text())
				);
			}
		}
	}

	void
	MainWindow::robotsSelectedFromScene (
		QGraphicsItem * newFocusItem,
		QGraphicsItem * oldFocusItem,
		Qt::FocusReason reason
	) {
		widget::RobotWidget * robot = dynamic_cast<widget::RobotWidget *>(newFocusItem);
		this->m_missionScene->unselectAll();
		this->m_internalUI._robotsList->clearSelection();
		if(robot == nullptr) return;
		this->m_missionScene->select(robot);
		QList<QListWidgetItem *> items = this->m_internalUI._robotsList->findItems(
			robot->name(),
			Qt::MatchExactly
		);
		this->m_internalUI._robotsList->setCurrentItem(items[0]);
	}

}; // namespace lis::pecase::productive40::missionplanner::ui