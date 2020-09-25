/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the implementation of a console logger.
 * \details This file provides the implementation of a console logger.
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
#include "../../../include/common/logging/console_logger_impl.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::logging {
	
#pragma region Constructors / Destructor

	ConsoleLoggerImpl::ConsoleLoggerImpl (
		void
	) :
		LoggerImpl() {
	}

	ConsoleLoggerImpl::~ConsoleLoggerImpl(
		void
	) {
	}

#pragma endregion

#pragma region Logging Operations

	void
	ConsoleLoggerImpl::write (
		unsigned long object
	) {
		std::cout << object;
	}


	void
	ConsoleLoggerImpl::write (
		long object
	) {
		std::cout << object;
	}

	void
	ConsoleLoggerImpl::write (
		double object
	) {
		std::cout << object;
	}

	void
	ConsoleLoggerImpl::write (
		char object
	) {
		std::cout << object;
	}

	void
	ConsoleLoggerImpl::write (
		const char * object
	) {
		std::cout << object;
	}

	void
	ConsoleLoggerImpl::write (
		const std::string & object
	) {
		std::cout << object;
	}

	void
	ConsoleLoggerImpl::endl (
		void
	) {
		std::cout << std::endl;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::common::logging