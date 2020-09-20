/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of a common environment for the Mission Planner.
 * \details This file provides the interface of a common environment for the Mission Planner.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
    Qt Include
===================================================================================================
*/
#include <QObject>
#include <QBuffer>
#include <QMutex>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include <common/pattern.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner {

#pragma region Types Definitions

	/**
	 * \class Environment include/missionplanner/environment.hpp \
	 * <productive40/missionplanner/environment.hpp>
	 * \brief Environment Class.
	 * \details This class implements a common environment in the Mission Planner.
	 * \nosubgrouping
	 */
    class Environment :
		public QObject,
		public common::pattern::Singleton<Environment> {

		friend class common::pattern::Singleton<Environment>;

		Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Buffer which simulates wireless transmission.
		 * \details Buffer which simulates wireless transmission.
		 */
		private:
		QBuffer
		m_environmentData;

		/**
		 * \brief Mutex for data transmission.
		 * \details Mutex for data transmission.
		 */
		private:
		QMutex
		m_dataMutex;

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
        private:
        Environment (
            void
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        private:
        ~Environment (
            void
        );

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Data Transmission
	 */
	#pragma region Data Transmission
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Sends a message through the environment.
		 * \details Sends a message through the environment.
		 * \param[in] data (const unsigned char *) Data to send through the environment.
		 * \param[in] size (size_t) Size of the data.
		 */
		public:
		void
		sendData (
			const unsigned char *,
			size_t
		);

		/**
		 * \brief Sends a message through the environment.
		 * \details Sends a message through the environment.
		 * \param[in] data (const unsigned char **) Pointer to a buffer where data will be stored.
		 * \param[in] size (size_t) Size of the read data.
		 */
		public:
		void
		readData (
			unsigned char *,
			size_t &
		);

		#pragma endregion

		#pragma region Signals

		/**
		 * \brief Signal emitted when data is ready to be read.
		 * \details Signal emitted when data is ready to be read.
		 */
		signals:
		void
		dataReadyRead (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class Environment

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner