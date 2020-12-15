/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of delegate for the Network Manager.
 * \details This file provides the interface of delegate for the Network Manager.
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

/*
===================================================================================================
	Project Include
===================================================================================================
*/
#include <common/pattern.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::network {

#pragma region Forward Declarations

	class NetworkManager;

#pragma endregion

#pragma region Types Definitions

	/**
	 * \interface NetworkManagerImpl include/missionplanner/network/network_manager_impl.hpp \
	 * <productive40/missionplanner/network/network_manager_impl.hpp>
	 * \brief NetworkManagerImpl class.
	 * \details This interface must be implemented by network manager delegates.
	 * \nosubgrouping
	 */
    class NetworkManagerImpl :
		public QObject {

		friend class NetworkManager;

		Q_OBJECT

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
        protected:
        NetworkManagerImpl (
            void
        ) = default;

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        protected: virtual
        ~NetworkManagerImpl (
            void
        ) = default;

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Broadcast Handler
	 */
	#pragma region Broadcast Handler
	/**@{*/

		#pragma region Signals

		/**
		 * \brief A network interface is ready to read message from broadcast.
		 * \details This signal should be trigger when a network delegate received a broadcasted
		 * message and is ready to dispatch it.
		 * \param[in] interface (const NetworkManagerImpl &) Network delegate from which messages
		 * are ready.
		 */
		signals:
		void
		broadcastMessageReceived (
			NetworkManagerImpl &
		);

		#pragma endregion

		#pragma region Abstract Methods

		/**
		 * \brief Read a broadcasted message.
		 * \details Allocate a buffer and store a message from the queue.
		 * \param[out] buffer (unsigned char *) Buffer where the message will be stored.
		 * \param[out] size (size_t &) Size of the buffer.
		 */
		protected: virtual
		void
		readFromBroadcast (
			unsigned char *,
			size_t &
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	#pragma region Client Management
	/**@{*/

		#pragma region Signals

		/**
		 * \brief A network interface received a message from a robot.
		 * \details This signal is trigger when a connected robot sent a message.
		 * \param[in] interface (const NetworkManagerImpl &) Network interfce.
		 * \param[in] address (std::string) Address of the robot.
		 */
		/*signals:
		void
		robotMessageReceived (
			NetworkManagerImpl &,
			std::string
		);*/

		#pragma endregion

		#pragma region Abstract Methods

		/**
		 * \brief Try to connect to a robot.
		 * \details Try to connect to a robot.
		 * \param[in] address (const unsigned char *) Address of the robot.
		 */
		/*protected: virtual
		void
		connectToRobot (
			const unsigned char *
		) = 0;*/

		/**
		 * \brief Read a message from a client.
		 * \details Allocate a buffer and store a message from the queue.
		 * \param[in] client (const std::string &) Address of the client.
		 * \param[out] buffer (unsigned char *) Buffer where the message will be stored.
		 * \param[out] size (size_t &) Size of the buffer.
		 */
		/*protected: virtual
		void
		recvFromRobot (
			const std::string &,
			unsigned char *,
			size_t &
		) = 0;*/

		/*protected: virtual
		void
		sendToRobot (
			const std::string &,
			unsigned char *,
			size_t &
		) = 0;*/

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class NetworkManagerImpl

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::network