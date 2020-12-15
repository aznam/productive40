/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of a window logger implementation.
 * \details This file provides the interface of a window logger implementation.
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

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtCore/QObject>
#include <QtCore/QString>

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <common/logging.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../ui.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application {

#pragma region Types Definitions

	/**
	 * \class WindowLoggerImpl include/missionplanner/application/window_logger_impl.hpp \
	 * <productive40/missionplanner/application/window_logger_impl.hpp>
	 * \brief Window Logger Implementation Interface.
	 * \details This class implements a logging in a window.
	 * \nosubgrouping
	 */
	class WindowLoggerImpl :
		public QObject,
		public common::logging::LoggerImpl {

		Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Window mutex.
		 * \details Window mutex.
		 */
		private:
		std::mutex
		m_windowMutex;

		/**
		 * \brief Text Edit resource.
		 * \details A pointer to a text edit resource.
		 */
		private:
		ui::LoggerWindow *
		m_logResource;

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
		 * \param[in] log_resource (ui::LoggerWindow *) Reference to the logger window.
		 */
		public:
		WindowLoggerImpl (
			ui::LoggerWindow &
		);

		#pragma endregion

		#pragma endregion Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~WindowLoggerImpl (
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

		#pragma region Signals

		/**
		 * \brief Used to append text to the window.
		 * \details Used to append text to the window.
		 */
		signals:
		void
		log2window (
			QString
		);

		#pragma endregion

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

	}; // class WindowLoggerImpl

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application