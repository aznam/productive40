/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Main Window of the mission planner.
 * \details This file provides the interface of the Main Window of the mission planner.
 */
#pragma once

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtWidgets/QMainWindow>
#include <QtCore/QTimer>
#include <QtCore/QElapsedTimer>

/*
===================================================================================================
    Generated Includes
===================================================================================================
*/
#include "ui_main_window.hpp"

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
        m_internalUI;

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

    }; // class MainWindow

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui