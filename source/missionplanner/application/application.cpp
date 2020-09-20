/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the application.
 * \details This file implements the main application.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../include/missionplanner/application/application.hpp"
#include "../../../include/missionplanner/application.hpp"
#include "../../../include/missionplanner/network.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application {

#pragma region Constructors / Destructor

	Application::Application (
		int argc,
		char ** argv
	) :
		QApplication(argc, argv),
		m_networkManager(network::NetworkManager::instance()) {

		// Setup the network manager for the Fake Communication
		this->m_networkManager.addNetworkDelegate(
			new network::delegate::FakeCommunicationImpl
		);

		// Setup the network manager for ROS Communication
		//this->m_networkManager.addNetworkDelegate(
		//	new network::delegate::RosCommunicationImpl
		//);

		// Setup the network manager for INET Communication
		//this->m_networkManager.addNetworkDelegate(
		//	new network::delegate::InetCommunicationImpl
		//);

		// Parse arguments
		for(unsigned i = 1; i < argc; i++) {

			// Simulated robots
			if(strcmp(argv[i], "--robot") == 0 && i+1 < argc) {
				unsigned int nb_robots = atoi(argv[i+1]);
				for(unsigned r = 0; r < nb_robots; r++) {
					Simubot* robot = new Simubot(this, r + 1);
					connect(robot, &Simubot::finished, this, &Application::robotTerminated);
					this->m_simubots.append(robot);
					robot->start();
				}
			}

		}

		// Show the main window
		this->m_mainWindow.show();
	}

	Application::~Application (
		void
	) {
		for(unsigned r = 0; r < this->m_simubots.size(); r++) {
			this->m_simubots[r]->exit(0);
		}
	}

#pragma endregion

#pragma region Simubot Functions

	void
	Application::robotTerminated (
		void
	) {
		Simubot* sender = (Simubot*)QObject::sender();
		disconnect(sender, &Simubot::finished, this, &Application::robotTerminated);
		delete sender;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application