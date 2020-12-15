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
namespace lis::pecase::productive40::missionplanner::environment {

#pragma region Types Definitions

	/**
	 * \class Environment include/missionplanner/environment/virtual_network.hpp \
	 * <productive40/missionplanner/environment/virtual_network.hpp>
	 * \brief Virtual Network Class.
	 * \details This class implements a virtual network that simulates network communication.
	 * \nosubgrouping
	 */
    class VirtualNetwork :
		public QObject {

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
        public:
        VirtualNetwork (
            void
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        public:
        ~VirtualNetwork (
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

		public:
		bool
		dataAvailable (
			void
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

    }; // class VirtualNetwork

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::environment