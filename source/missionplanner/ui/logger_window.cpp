/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the logger window.
 * \details This file implements the logger window of the mission planner.
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
#include "../../../include/missionplanner/application.hpp"
#include "../../../include/missionplanner/globals.hpp"
#include "../../../include/missionplanner/ui/logger_window.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui {

#pragma region Constructors / Destructor

    LoggerWindow::LoggerWindow (
        QWidget * parent
    ) :
		QDockWidget(parent) {
        this->m_internalUITemplate.setupUi(this);

		logger_.addlogger(
			*new application::WindowLoggerImpl(*this)
		);
    }

    LoggerWindow::~LoggerWindow (
        void
    ) {
		QObject::disconnect(this);
    }

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Logging Operations

	void
	LoggerWindow::log (
		const QString & text
	) {
		this->m_internalUITemplate._loggerTextEdit->moveCursor(QTextCursor::End);
		this->m_internalUITemplate._loggerTextEdit->insertPlainText(text);
		this->m_internalUITemplate._loggerTextEdit->moveCursor(QTextCursor::End);
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui