/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface allowing fake communication with simulation robots.
 * \details This file provides the interface allowing fake communication with simulation robots.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Standard Include
===================================================================================================
*/
#include <map>

/*
===================================================================================================
	Qt Include
===================================================================================================
*/
#include <QLocalSocket>

/*
===================================================================================================
	Project Include
===================================================================================================
*/
#include "../network_manager_impl.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::network::delegate {

#pragma region Types Definitions

	/**
	 * \class FakeCommunicationImpl \
	 * include/missionplanner/network/delegate/fake_communication_impl.hpp \
	 * <productive40/missionplanner/network/delegate/fake_communication_impl.hpp>
	 * \brief FakeCommunication Implementation.
	 * \details This class allows the Network Manager to communicate through fake communication
	 * system.
	 * \nosubgrouping
	 */
    class FakeCommunicationImpl :
		public NetworkManagerImpl {

		friend class NetworkManager;

		Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief List of current client connected.
		 * \details List of current client connected.
		 */
		private:
		std::map<std::string, QLocalSocket *>
		m_clients;

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
		FakeCommunicationImpl (
            void
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        public:
        ~FakeCommunicationImpl (
            void
        );

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Broadcast Handler
	 */
	#pragma region Broadcast Handler
	/**@{*/

		#pragma region Overriden Methods

		/**
		 * \brief Read a message from the queue.
		 * \details Allocate a buffer and store a message from the queue.
		 * \param[out] buffer (char *) Buffer where the message will be stored.
		 * \param[out] size (size_t &) Size of the buffer.
		 */
		protected:
		void
		broadcastRead (
			unsigned char *,
			size_t &
		) override;

		#pragma endregion

	/**@}*/
	#pragma endregion

	#pragma region Client Management
	/**@{*/

		#pragma region Overriden Methods

		/**
		 * \brief Try to connect to a robot.
		 * \details Try to connect to a robot.
		 * \param[in] address (const unsigned char *) Address of the robot.
		 */
		protected:
		void
		connectClient (
			const unsigned char *
		) override;

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class FakeCommunicationImpl

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::network::delegate