/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the implementation of a logger.
 * \details This file provides the implementation of a logger.
 */
#pragma once

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "logger.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::logging {
	
#pragma region Logging Operations

	template <
		typename Type
	> void
	Logger::write (
		const Type & object
	) {
		this->m_loggerLock.lock();
		for(auto l : this->m_loggersImpl) {
			l.first->write(object);
		}
		this->m_loggerLock.unlock();
	}

	template <
		typename Type
	> Logger &
	Logger::operator<< (
		const Type & object
	) {
		this->write(object);
		return *this;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::common::logging