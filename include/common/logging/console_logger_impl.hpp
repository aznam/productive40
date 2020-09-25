/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of a console logger implementation.
 * \details This file provides the interface of a console logger implementation.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

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
	 * \class ConsoleLoggerImpl include/common/logging/console_logger_impl.hpp \
	 * <productive40/common/logging/console_logger_impl.hpp>
	 * \brief Console Logger Implementation Interface.
	 * \details This class implements a logging in the console.
	 * \nosubgrouping
	 */
	class ConsoleLoggerImpl :
		public LoggerImpl {

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
		ConsoleLoggerImpl (
			void
		);

		#pragma endregion

		#pragma endregion Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~ConsoleLoggerImpl (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Logging Operations
	 */
	#pragma region Logging Operations
	/**@{*/

		#pragma region Overriden Methods

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (unsigned long) Object to log.
		 */
		public:
		void
		write (
			unsigned long
		) override;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (long) Object to log.
		 */
		public:
		void
		write (
			long
		) override;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (double) Object to log.
		 */
		public:
		void
		write (
			double
		) override;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (char) Object to log.
		 */
		public:
		void
		write (
			char
		) override;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (const char *) Object to log.
		 */
		public:
		void
		write (
			const char *
		) override;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (const std::string &) Object to log.
		 */
		public:
		void
		write (
			const std::string &
		) override;

		/**
		 * \brief EoL Function.
		 * \details EoL Function.
		 */
		public:
		void
		endl (
			void
		) override;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class LoggerImpl

#pragma endregion

}; // namespace lis::pecase::productive40::common::logging