/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an implementation allowing fake communication with simulation robots.
 * \details This file implements a system allowing fake communication with simulation robots.
 */

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <common/strutils.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/network/delegate/ros_communication_impl.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::network::delegate {
	
#pragma region Constructors / Destructor
	
	ROSCommunicationImpl::ROSCommunicationImpl (
		int argc,
		char ** argv
	) :
		network::NetworkManagerImpl()/*,
		m_rosManager(rosproxy::ROSManager::instance())*/ {

		//this->m_rosManager.init(argc, argv, "mission_planner");
		//m_rosManager.subscribeTopic(rosproxy::Environment_Topic);
	}

	ROSCommunicationImpl::~ROSCommunicationImpl (
		void
	) {
		//this->m_rosManager.close();
	}

#pragma endregion

#pragma region Methods Definitions and Implementations

	#pragma region Broadcast Handler

		void
		ROSCommunicationImpl::readFromBroadcast (
			unsigned char * message,
			size_t & size
		) {
		}

	#pragma endregion

	#pragma region Client Management

	/*void
	ROSCommunicationImpl::connectToRobot (
		const unsigned char * address
	) {
	}

	void
	ROSCommunicationImpl::recvFromRobot (
		const std::string & client,
		unsigned char * buffer,
		size_t & size
	) {
	}

	void
	ROSCommunicationImpl::sendToRobot (
		const std::string & client,
		unsigned char * buffer,
		size_t & size
	) {
	}*/

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::network::delegate