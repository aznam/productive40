/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the implementation of a logger.
 * \details This file provides the implementation of a logger.
 */

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../include/common/logging/logger.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::logging {
	
#pragma region Constructors / Destructor

	Logger::Logger (
		void
	) :
		m_loggersImpl(),
		m_loggerMutex() {
	}

	Logger::~Logger (
		void
	) {
		for(auto l : this->m_loggersImpl) {
			if(l.second) delete l.first;
		}
		this->m_loggersImpl.clear();
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Loggers Management

	void
	Logger::addlogger (
		const LoggerImpl & logger,
		bool destroy_on_delete
	) {
		this->m_loggersImpl.push_back(std::make_pair((LoggerImpl *)&logger, destroy_on_delete));
	}

	#pragma endregion

	#pragma region Logging Operations

	Logger &
	Logger::endl (
		const Logger & logger
	) {
		for(auto l : logger.m_loggersImpl) {
			l.first->endl();
		}

		return (Logger &)logger;
	}

	Logger &
	Logger::operator<< (
		Logger & (*func_ptr)(const Logger &)
	) {
		return func_ptr(*this);
	}

	#pragma endregion

	#pragma region Resources Management

	void
	Logger::lock (
		void
	) {
		for(auto l : this->m_loggersImpl) {
			l.first->acquireResource();
		}
	}

	void
	Logger::unlock (
		void
	) {
		for(auto l : this->m_loggersImpl) {
			l.first->releaseResource();
		}
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::common::logging