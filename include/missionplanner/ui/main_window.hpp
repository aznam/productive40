/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Main Window of the mission planner.
 * \details This file provides the interface of the Main Window of the mission planner.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtWidgets/QMainWindow>
#include <QtCore/QList>

/*
===================================================================================================
    Generated Includes
===================================================================================================
*/
#include <ui_main_window.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../robot.hpp"
#include "logger_window.hpp"
#include "inspector_window.hpp"
#include "widget/mission_scene.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui {
     
#pragma region Types Definitions

	/**
	 * \class MainWindow include/missionplanner/ui/main_window.hpp \
	 * <productive40/missionplanner/ui/main_window.hpp>
	 * \brief Main Window.
	 * \details This class represents the Main Window of the Mission Planner.
	 * \nosubgrouping
	 */
    class MainWindow : 
        public QMainWindow {

        Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief MainWindow delegate.
		 * \details Delegation to main window internal class.
		 */
        private:
        Ui::MainWindowInternal
        m_internalUITemplate;

		/**
		 * \brief Logger window.
		 * \details Logger window.
		 */
		private:
		LoggerWindow
		m_loggerWindow;

		/**
		 * \brief Inspector window.
		 * \details Inspector window.
		 */
		private:
		InspectorWindow
		m_inspectorWindow;

		/**
		 * \brief Mission scene.
		 * \details Mission scene.
		 */
		private:
		widget::MissionScene
		m_missionScene;

	/**@}*/
    #pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
    #pragma region Constructors / Destructor
	/**@{*/

        #pragma region Constructor

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 * \param[in] parent (QWidget *) Default parent.
		 */
        public:
        MainWindow (
            QWidget * = Q_NULLPTR
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        public:
        ~MainWindow (
            void
        );

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Main Menu Actions
	 */
	#pragma region Main Menu Actions
	/**@{*/

		#pragma region Slots

		/**
		 * \brief Display logger output.
		 * \details Display logger output.
		 */
		private slots:
		void
		displayLoggerOutput (
			void
		);

		/**
		 * \brief Display inspector.
		 * \details Display inspector.
		 */
		private slots:
		void
		displayInspector (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Application Flow
	 */
	#pragma region Application Flow
	/**@{*/

		#pragma region Signals

		/**
		 * \brief Exit the application.
		 * \details Exit the application.
		 * \param[in] exit_code (unsigned int) Exit code.
		 */
		signals:
		void
		exitApplication (
			unsigned int
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot-related Events
	 */
	#pragma region Robot-related Events
	/**@{*/

		#pragma region Slots

		/**
		* \brief Select robots.
		* \details Called when robots are selected in the mission planner.
		* \param[in] robots (const QList<const robot::RobotModel &> &) List of robots.
		* \param[in] source (QObject *) Source of the initial signal.
		*/
		public slots:
		void
		selectRobots (
			const QList<const robot::RobotModel *> &,
			QObject * = nullptr
		);

		/**
		 * \brief Display a robot.
		 * \details Display a robot.
		 * \param[in] robot_model (const robot::RobotModel &) Reference to the robot.
		 */
		public slots:
		void
		displayRobot (
			const robot::RobotModel &
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class MainWindow

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui