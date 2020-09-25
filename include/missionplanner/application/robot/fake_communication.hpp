/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an interface for a fake communication system (for simulated robots).
 * \details This file provides an interface for a fake communication system (for simulated robots).
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
#include <memory>

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QLocalServer>
#include <QLocalSocket>
#include <QObject>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include <robotapi/communication.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {

#pragma region Types Definitions

	/**
	 * \class FakeCommunication include/missionplanner/application/robot/fake_communication.hpp \
	 * <productive40/missionplanner/application/robot/fake_communication.hpp>
	 * \brief Fake Communication Interface.
	 * \details This class implements a fake communication system for simubot.
	 * \nosubgrouping
	 */
    class FakeCommunication :
		public QObject,
		public robotapi::communication::CommunicationInterface {

		Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/
		
		/**
		 * \brief Local Server to exchange information with the robot.
		 * \details Local Server to exchange information with the robot.
		 */
		private:
		QLocalServer
		m_server;

		/**
		 * \brief Pointer to the client socket.
		 * \details Pointer to the client socket.
		 */
		private:
		QLocalSocket *
		m_client;

		private:
		bool
		m_dataAvailable;

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
		FakeCommunication (
			void
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~FakeCommunication (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Communication Handling
	 */
	#pragma region Communication Handling
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Start the server.
		 * \details Start the server on a specific socket.
		 * \param[in] name (const std::string &) Name of the socket.
		 */
		public:
		void
		listen (
			const std::string &
		);

		#pragma endregion

		#pragma region Slots

		/**
		 * \brief Accept pending connections.
		 * \details Accept pending connections.
		 */
		private slots:
		void
		pendingClientConnection (
			void
		);

		private slots:
		void
		lostClientConnection (
			void
		);

		private slots:
		void
		readyClientRead (
			void
		);

		#pragma endregion

		#pragma region Overriden Methods

		/**
		 * \brief Indicates if the robot is currently connected to a mission planner.
		 * \details Indicates if the robot is currently connected to a mission planner.
		 * \retval true The robot is corrently connected to a mission planner.
		 * \retval false The robot is currently disconnected.
		 */
		public:
		bool
		connected (
			void
		) const override;

		/**
		 * \brief Broadast a message.
		 * \details Broadcast a message on a network or air.
		 * \param[in] message (const char *) Array of bytes to broadcast.
		 * \param[in] size (unsigned long) Size of the message.
		 */
		public:
		void
		broadcast (
			const unsigned char *,
			unsigned long
		) override;

		/**
		 * \brief Send a message.
		 * \details Send a message to a client.
		 * \param[in] message (const char *) Array of bytes to send.
		 * \param[in] size (unsigned long) Size of the message.
		 */
		public:
		void
		send (
			const unsigned char *,
			unsigned long
		) override;

		public:
		void
		recv (
			unsigned char *,
			unsigned long
		) override;

		public: bool
		requested (
			void
		) const override;

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class FakeCommunication

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot