/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of a logger implementation.
 * \details This file provides the interface of a logger implementation.
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
#include <string>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::logging {

#pragma region Types Definitions

	/**
	 * \interface LoggerImpl include/common/logging/logger_impl.hpp \
	 * <productive40/common/logging/logger_impl.hpp>
	 * \brief Logger Implementation Interface.
	 * \details This interface provides an easy way to implement logger.
	 * \nosubgrouping
	 */
	class LoggerImpl {

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
		LoggerImpl (
			void
		) = default;

		#pragma endregion

		#pragma endregion Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public: virtual
		~LoggerImpl (
			void
		) = default;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Resource Handling
	 */
	#pragma region Resource Handling
	/**@{*/

		#pragma region Abstract Methods

		/**
		 * \brief Acquire a resource mutex.
		 * \details Acquire a resource mutex.
		 */
		public: virtual
		void
		acquireResource (
			void
		) = 0;

		/**
		 * \brief Release a resource mutex.
		 * \details Release a resource mutex.
		 */
		public: virtual
		void
		releaseResource (
			void
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Logging Operations
	 */
	#pragma region Logging Operations
	/**@{*/

		#pragma region Abstract Methods

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (unsigned long) Object to log.
		 */
		public: virtual
		void
		write (
			unsigned long
		) = 0;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (int) Object to log.
		 */
		public: virtual
		void
		write (
			long
		) = 0;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (double) Object to log.
		 */
		public: virtual
		void
		write (
			double
		) = 0;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (char) Object to log.
		 */
		public: virtual
		void
		write (
			char
		) = 0;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (const char *) Object to log.
		 */
		public: virtual
		void
		write (
			const char *
		) = 0;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (const std::string &) Object to log.
		 */
		public: virtual
		void
		write (
			const std::string &
		) = 0;

		/**
		 * \brief EoL Function.
		 * \details EoL Function.
		 */
		public: virtual
		void
		endl (
			void
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class LoggerImpl

#pragma endregion

}; // namespace lis::pecase::productive40::common::logging