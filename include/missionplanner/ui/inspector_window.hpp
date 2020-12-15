/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Inspector Window of the mission planner.
 * \details This file provides the interface of the Inspector Window of the mission planner.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	General Includes
===================================================================================================
*/
#include <map>

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtWidgets/QDockWidget>
#include <QtGui/QStandardItemModel>
#include <QTimer>

/*
===================================================================================================
    Generated Includes
===================================================================================================
*/
#include <ui_inspector_window.hpp>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../robot.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui {
     
#pragma region Types Definitions

	/**
	 * \class InspectorWindow include/missionplanner/ui/inspector_window.hpp \
	 * <productive40/missionplanner/ui/inspector_window.hpp>
	 * \brief Inspector Window.
	 * \details This class represents the Inspector Window of the Mission Planner.
	 * \nosubgrouping
	 */
    class InspectorWindow : 
        public QDockWidget {

        Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief InspectorWindow delegate.
		 * \details Delegation to inspector window internal class.
		 */
        private:
        Ui::InspectorWindowInternal
        m_internalUITemplate;

		/**
		 * \brief Model containing inspector data.
		 * \details Model containing inspector data.
		 */
		private:
		QStandardItemModel
		m_robotTableModel;

		/**
		 * \brief Map contaning robots.
		 * \details Map containing robots.
		 */
		private:
		std::map<const robot::RobotModel *, QListWidgetItem *>
		m_robotsList;

		QTimer m_timer;

	/**@}*/
    #pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
    #pragma region Constructors / Destructor
	/**@{*/

		void
		refresh();

        #pragma region Constructor

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 * \param[in] parent (QWidget *) Default parent.
		 */
        public:
        InspectorWindow (
            QWidget * = Q_NULLPTR
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        public:
        ~InspectorWindow (
            void
        );

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Robots Management
	 */
	#pragma region Robots Management
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Create a robot widget on the same from a robot model.
		 * \details Create a robot widget on the same from a robot model.
		 * \param[in] robot_model (const robot::RobotModel &) Source robot model.
		 */
		public:
		void
		addRobot (
			const robot::RobotModel &
		);

		/**
		 * \brief Performs operations when robots are selected.
		 * \details Performs operations when robots are selected.
		 * \param[in] robots (const QList<const robot::RobotModel &> &) List of robots.
		 */
		public:
		void
		selectRobots (
			const QList<const robot::RobotModel *> &
		);

		/**
		 * \brief Display robot details.
		 * \details Display robot details
		 * \param[in] robot (const robot::RobotModel &) Source robot model.
		 */
		private:
		void
		displayRobot (
			const robot::RobotModel &
		);

		#pragma endregion

		#pragma region Slots

		signals:
		void
		sendCommand (
			void	
		);

		#pragma endregion

		#pragma region Signals

		/**
		 * \brief Signal emitted when a robot is selected in the list.
		 * \details Signal emitted when a robot is selected in the list.
		 * \param[in] robot_model (const robot::RobotModel &) Reference to the robot model.
		 * \param[in] signal (QWidget *) Source of the initial signal.
		 */
		signals:
		void
		selectedRobots (
			const QList<const robot::RobotModel *> &,
			QObject *
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class InspectorWindow

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui