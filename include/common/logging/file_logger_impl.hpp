/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of a file logger implementation.
 * \details This file provides the interface of a file logger implementation.
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
#include <mutex>
#include <fstream>

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
	 * \class FileLoggerImpl include/common/logging/file_logger_impl.hpp \
	 * <productive40/common/logging/file_logger_impl.hpp>
	 * \brief File Logger Implementation Interface.
	 * \details This class implements a logging in a file.
	 * \nosubgrouping
	 */
	class FileLoggerImpl :
		public LoggerImpl {

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief File mutex.
		 * \details File mutex.
		 */
		private:
		std::mutex
		m_fileMutex;

		/*
		 * \brief Stream object.
		 * \details Internal Stream object.
		 */
		private:
		std::ofstream
		m_fileStream;

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
		FileLoggerImpl (
			const char* filename
		);

		#pragma endregion

		#pragma endregion Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~FileLoggerImpl (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Resource Handling
	 */
	#pragma region Resource Handling
	/**@{*/

		#pragma region Overriden Methods

		/**
		 * \brief Acquire a resource mutex.
		 * \details Acquire a resource mutex.
		 */
		public:
		void
		acquireResource (
			void
		) override;

		/**
		 * \brief Release a resource mutex.
		 * \details Release a resource mutex.
		 */
		public: virtual
		void
		releaseResource (
			void
		) override;

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
		 * \param[in] object (uint32) Object to log.
		 */
		public:
		void
		write (
			uint32
		) override;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (int32) Object to log.
		 */
		public:
		void
		write (
			int32
		) override;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (uint64) Object to log.
		 */
		public:
		void
		write (
			uint64
		) override;

		/**
		 * \brief Logging.
		 * \details Logging.
		 * \param[in] object (int64) Object to log.
		 */
		public:
		void
		write (
			int64
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

	}; // class FileLoggerImpl

#pragma endregion

}; // namespace lis::pecase::productive40::common::logging