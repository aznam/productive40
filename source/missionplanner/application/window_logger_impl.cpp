/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the implementation of a window logger.
 * \details This file provides the implementation of a window logger.
 */
#pragma once

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
#include "../../../include/missionplanner/application/window_logger_impl.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application {
	
#pragma region Constructors / Destructor

	WindowLoggerImpl::WindowLoggerImpl (
		ui::LoggerWindow & log_resource
	) :
		common::logging::LoggerImpl(),
		m_logResource(&log_resource),
		m_windowMutex() {
		QObject:connect(
			this,
			&WindowLoggerImpl::log2window,
			this->m_logResource,
			&ui::LoggerWindow::log
		);
	}

	WindowLoggerImpl::~WindowLoggerImpl(
		void
	) {
		QObject:disconnect(this);
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Resources Handling

	void
	WindowLoggerImpl::acquireResource (
		void
	) {
		this->m_windowMutex.lock();
	}

	void
	WindowLoggerImpl::releaseResource (
			void
	) {
		this->m_windowMutex.unlock();
	}

	#pragma endregion

	#pragma region Logging Operations

	void
	WindowLoggerImpl::write (
		uint32 object
	) {
		emit this->log2window(QString::number(object));
	}


	void
	WindowLoggerImpl::write (
		int32 object
	) {
		emit this->log2window(QString::number(object));
	}

	void
	WindowLoggerImpl::write (
		uint64 object
	) {
		emit this->log2window(QString::number(object));
	}


	void
	WindowLoggerImpl::write (
		int64 object
	) {
		emit this->log2window(QString::number(object));
	}

	void
	WindowLoggerImpl::write (
		double object
	) {
		emit this->log2window(QString::number(object));
	}

	void
	WindowLoggerImpl::write (
		char object
	) {
		emit this->log2window(QString::number(object));
	}

	void
	WindowLoggerImpl::write (
		const char * object
	) {
		emit this->log2window(QString(object));
	}

	void
	WindowLoggerImpl::write (
		const std::string & object
	) {
		emit this->log2window(QString::fromStdString(object));
	}

	void
	WindowLoggerImpl::endl (
		void
	) {
		emit this->log2window("\n");
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application