/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief 
 * \details 
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
#include <set>

/*
===================================================================================================
	ROS Include
===================================================================================================
*/
//#include <rosproxy.hpp>

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

    class ROSCommunicationImpl :
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
		std::set<std::string>
		m_clients;

		/*private:
		rosproxy::ROSManager &
		m_rosManager;*/

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
		ROSCommunicationImpl (
            int,
			char **
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        public:
        ~ROSCommunicationImpl (
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
		readFromBroadcast (
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
		/*protected:
		void
		connectToRobot (
			const unsigned char *
		) override;*/

		/**
		 * \brief Read a message from a client.
		 * \details Allocate a buffer and store a message from the queue.
		 * \param[in] client (const std::string &) Address of the client.
		 * \param[out] buffer (unsigned char *) Buffer where the message will be stored.
		 * \param[out] size (size_t &) Size of the buffer.
		 */
		/*protected:
		void
		recvFromRobot (
			const std::string &,
			unsigned char *,
			size_t &
		) override;

		protected:
		void
		sendToRobot (
			const std::string &,
			unsigned char *,
			size_t &
		) override;*/

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class FakeCommunicationImpl

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::network::delegate