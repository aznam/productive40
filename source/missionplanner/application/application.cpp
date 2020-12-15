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
#include "../../../include/missionplanner/robot.hpp"
#include "../../../include/missionplanner/application/application.hpp"
#include "../../../include/missionplanner/globals.hpp"

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

		virtual_network_ = new environment::VirtualNetwork;

		// Setup the network manager for the Fake Communication
		this->m_networkManager.addNetworkDelegate(
			new network::delegate::FakeCommunicationImpl
		);

		// Setup the network manager for ROS Communication
	//#if !defined(_DEBUG)

		this->m_networkManager.addNetworkDelegate(
			new network::delegate::ROSCommunicationImpl(argc, argv)
		);

	//#endif

		// Setup the network manager for INET Communication
		//this->m_networkManager.addNetworkDelegate(
		//	new network::delegate::InetCommunicationImpl
		//);

		// Setup view subscriber
		//this->m_networkManager.subscribe(&this->m_mainWindow);

		// Configure the main window
		QObject::connect(
			&this->m_mainWindow,
			&ui::MainWindow::exitApplication,
			this,
			&Application::exit,
			Qt::QueuedConnection
		);

		QObject::connect(
			&missionplanner::robot::RobotManager::instance(),
			&missionplanner::robot::RobotManager::displayRobot,
			&this->m_mainWindow,
			&ui::MainWindow::displayRobot
		);

		// Parse arguments
		for(unsigned i = 1; i < argc; i++) {

			// Simulated robots
			if(strcmp(argv[i], "--robot") == 0 && i + 1 < argc) {
				unsigned int nb_robots = atoi(argv[i + 1]);
				for(unsigned r = 1; r <= nb_robots; r++) {
					this->createRobot(r);
				}
			}

		}

		this->m_mainWindow.show();
	}

	Application::~Application (
		void
	) {
		QObject::disconnect(
			&missionplanner::robot::RobotManager::instance(),
			&missionplanner::robot::RobotManager::displayRobot,
			&this->m_mainWindow,
			&ui::MainWindow::displayRobot
		);

		for(unsigned r = 0; r < this->m_simubots.size(); r++) {
			this->m_simubots[r]->exit(0);
		}

		QObject::disconnect(this);

		delete virtual_network_;
	}

#pragma endregion

#pragma region Methods Definitions and Implementations

	#pragma region Application Management

	void
	Application::exit (
		unsigned int exit_code
	) {
		QCoreApplication::exit(exit_code);
	}

	#pragma endregion

	#pragma region Simubot Functions

	Simubot *
	Application::createRobot (
		unsigned int robot_idx
	) {
		Simubot * robot = new Simubot(this, robot_idx);
		QObject::connect(robot, &Simubot::finished,	this, &Application::robotTerminated);
		this->m_simubots.append(robot);
		robot->start();
		missionplanner::robot::RobotManager::instance().robotConnected(&robot->m_robotInterface);
		return robot;
	}

	void
	Application::robotTerminated (
		void
	) {
		Simubot* robot = (Simubot*)QObject::sender();
		QObject::disconnect(robot, nullptr, this, nullptr);
		delete robot;
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application