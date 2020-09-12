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
		QMainWindow(parent) {
        m_internalUI.setupUi(this);
    }

    MainWindow::~MainWindow (
        void
    ) {
    }

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui
