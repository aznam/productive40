/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of a logger.
 * \details This file provides the interface of a logger.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Standard Includes
===================================================================================================
*/
#include <vector>
#include <mutex>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "logger_impl.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::logging {

#pragma region Types Definitions

	/**
	 * \class Logger include/common/logging/logger.hpp \
	 * <productive40/common/logging/logger.hpp>
	 * \brief Logger.
	 * \details This class provides a facade to manipulate easily loggers.
	 * \nosubgrouping
	 */
	class Logger {

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief List of loggers.
		 * \details List of loggers.
		 */
		private:
		std::vector<LoggerImpl *>
		m_loggersImpl;

		/**
		 * \brief Internal lock.
		 * \details Internal lock.
		 */
		private:
		std::unique_lock<std::mutex>
		m_loggerLock;

		/**
		 * \brief Mutex.
		 * \details Mutex.
		 */
		private:
		std::mutex
		m_loggerMutex;

	/**@}*/
	#pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Constructors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 */
		public:
		Logger (
			void
		);

		#pragma endregion

		#pragma endregion Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~Logger (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Loggers Managements
	 */
	#pragma region Loggers Management
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Add a logger.
		 * \details Add a logger.
		 * \param[in] logger (const LoggerImpl &) Logger.
		 */
		public:
		void
		addlogger (
			const LoggerImpl &
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Logging Operations
	 */
	#pragma region Logging Operations
	/**@{*/

		#pragma region Static Functions

		/**
		 * \brief End-of-Line.
		 * \details End-of-Line.
		 * \param[in] logger (const Logger &) Reference to the logger.
		 */
		public: static
		Logger &
		endl (
			const Logger &
		);

		#pragma endregion

		#pragma region Instance Methods

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \tparam Type Type of the lement to log.
		 * \param[in] object (const Type &) Object to log.
		 */
		private:
		template <
			typename Type
		> void
		write (
			const Type &
		);

		#pragma endregion

		#pragma region Operators

		/**
		 * \brief Alias for write.
		 * \details Alias for write.
		 * \tparam Type Type of the lement to log.
		 * \param[in] object (const Type &) Object to log.
		 */
		public:
		template <
			typename Type
		> Logger &
		operator<< (
			const Type &
		);

		/**
		 * \brief Helper for calling functions.
		 * \details Helper for calling functions.
		 * \param[in] func_ptr (Logger & (const Logger &)) Pointer to a function.
		 */
		public:
		Logger &
		operator<< (
			Logger & (*)(const Logger &)
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class Logger

#pragma endregion

}; // namespace lis::pecase::productive40::common::logging

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "logger.tpp"