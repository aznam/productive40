/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the implementation of a file logger.
 * \details This file provides the implementation of a file logger.
 */
#pragma once

/*
===================================================================================================
    Standard Includes
===================================================================================================
*/
#include <iostream>
#include <exception>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../include/common/logging/file_logger_impl.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::logging {
	
#pragma region Constructors / Destructor

	FileLoggerImpl::FileLoggerImpl (
		const char* filename
	) :
		LoggerImpl(),
		m_fileMutex(),
		m_fileStream() {
		m_fileStream.open(filename, std::ofstream::out | std::ofstream::trunc);

		if(m_fileStream.fail() || m_fileStream.bad() || m_fileStream.is_open() == false) {
			throw std::exception("LoggerFile: Cannot open file.");
		}
	}

	FileLoggerImpl::~FileLoggerImpl(
		void
	) {
		m_fileStream.flush();
		m_fileStream.close();
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Resources Handling

	void
	FileLoggerImpl::acquireResource (
		void
	) {
		this->m_fileMutex.lock();
	}

	void
	FileLoggerImpl::releaseResource (
			void
	) {
		this->m_fileMutex.unlock();
	}

	#pragma endregion

	#pragma region Logging Operations

	void
	FileLoggerImpl::write (
		uint32 object
	) {
		m_fileStream << object;
	}


	void
	FileLoggerImpl::write (
		int32 object
	) {
		m_fileStream << object;
	}

	void
	FileLoggerImpl::write (
		uint64 object
	) {
		m_fileStream << object;
	}


	void
	FileLoggerImpl::write (
		int64 object
	) {
		m_fileStream << object;
	}

	void
	FileLoggerImpl::write (
		double object
	) {
		m_fileStream << object;
	}

	void
	FileLoggerImpl::write (
		char object
	) {
		m_fileStream << object;
	}

	void
	FileLoggerImpl::write (
		const char * object
	) {
		m_fileStream << object;
	}

	void
	FileLoggerImpl::write (
		const std::string & object
	) {
		m_fileStream << object;
	}

	void
	FileLoggerImpl::endl (
		void
	) {
		m_fileStream << std::endl;
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::common::logging