/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Network Manager.
 * \details This file provides the interface of the Network Manager.
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
#include <vector>
#include <map>
#include <functional>

/*
===================================================================================================
    Qt Include
===================================================================================================
*/
#include <QObject>

/*
===================================================================================================
	Workspace Include
===================================================================================================
*/
#include <common/pattern.hpp>
#include <robotapi.hpp>

/*
===================================================================================================
	Project Include
===================================================================================================
*/
#include "network_manager_impl.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::network {

#pragma region Types Definitions

	/**
	 * \class NetworkManager include/missionplanner/network/network_manager.hpp \
	 * <productive40/missionplanner/network/network_manager.hpp>
	 * \brief NetworkManager class.
	 * \details The network manager is responsible of the network communication between the
	 * mission planner and the robots. Especially, it manages connection, disconnection,
	 * send and receiving data through different network & I/O devices.
	 * \nosubgrouping
	 */
    class NetworkManager :
		public QObject,
		public common::pattern::Singleton<NetworkManager>
		/*public common::pattern::Observable<NetworkInterface>*/ {

		friend class common::pattern::Singleton<NetworkManager>;

		Q_OBJECT

	/**
	 * \name Types Definitions
	 */
	#pragma region Types Definitions
	/**@{*/

		/**
		 * \brief Typedef for parsing functions.
		 * \details Typedef for parsing functions.
		 */
		typedef std::function<void (NetworkManagerImpl &, const unsigned char *)> MessageFunc;

	/**@}*/
	#pragma endregion

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Vector of Simulated Robot.
		 * \details Number of simulated robots to run.
		 */
		private:
		std::vector<NetworkManagerImpl *>
		m_delegates;

		/**
		 * \brief Map of messages functions.
		 * \details Map of messages functions.
		 */
		private:
		std::map<robotapi::communication::MessageCode, MessageFunc>
		m_messageFunc;

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
        NetworkManager (
            void
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 * \note The destructor deletes all the delegates associated to the manager.
		 */
        private:
        ~NetworkManager (
            void
        );

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Delegates Handling
	 */
	#pragma region Delegates Handling
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Add a delegate.
		 * \details Add a delegate.
		 * \param[in] delegate (NetworkManagerImpl *) Pointer to the delegate.
		 */
		public:
		void
		addNetworkDelegate (
			NetworkManagerImpl *
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Broadcast Handler
	 */
	#pragma region Broadcast Handler
	/**@{*/

		#pragma region Slots

		/**
		 * \brief A network interface is ready to read message from broadcast.
		 * \details This signal should be trigger when a network delegate received a broadcasted
		 * message and is ready to dispatch it.
		 * \param[in] interface (const NetworkManagerImpl &) Network delegate from which messages
		 * are ready.
		 */
		public slots:
		void
		broadcastAvailable (
			NetworkManagerImpl &
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Client Handler
	 */
	#pragma region Client Handler
	/**@{*/

		#pragma region Slots

		/**
		 * \brief A network interface received a message from a robot.
		 * \details This signal is trigger when a connected robot sent a message.
		 * \param[in] interface (const NetworkManagerImpl &) Network interfce.
		 * \param[in] address (std::string) Address of the robot.
		 */
		/*public slots:
		void
		dataAvailable (
			NetworkManagerImpl &,
			std::string
		);*/

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Message Parsing
	 */
	#pragma region Message Parsing
	/**@{*/

		/**
		 * \brief Parse a message and call the appropriate parsing function.
		 * \details Parse a message and call the appropriate parsing function.
		 * \param[in] interface (NetworkManagerImpl &) Source interface.
		 * \param[in] buffer (const unsigned char *) Buffer containing the message.
		 */
		public:
		void
		parse (
			NetworkManagerImpl &,
			const unsigned char *
		);

		/**
		 * \brief Discovery Message Handler.
		 * \details Discovery Message Handler.
 		 * \param[in] interface (NetworkManagerImpl &) Source interface.
		 * \param[in] buffer (const unsigned char *) Buffer containing the message.
		 */
		/*private:
		void
		discoveryHandler (
			NetworkManagerImpl &,
			const unsigned char *
		);

		private:
		void
		welcomeHandler (
			NetworkManagerImpl &,
			const unsigned char *
		);*/

	/**@}*/
	#pragma endregion

    }; // class NetworkManager

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::network