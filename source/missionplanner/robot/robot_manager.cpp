/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the robot manager.
 * \details This file implements the robot maanger.
 */

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include <common/strutils.hpp>
#include "../../../include/missionplanner/robot/robot_manager.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::robot {

#pragma region Constructors / Destructor

	RobotManager::RobotManager (
		void
    ) :
		QObject(nullptr),
		common::pattern::Singleton<RobotManager>(),
		m_robots() {
    }

    RobotManager::~RobotManager (
        void
    ) {
		for(RobotModel * robot : this->m_robots) delete robot;
    }

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Robots Management

	void
	RobotManager::robotConnected (
		application::robot::SimubotInterface * robotInterface
	) {
		RobotModel * robot = new RobotModel;
		robot->_identifier = common::strutils::atohex(
			(byte*)robotInterface->hardware()->robotInformations()._identifier,
			sizeof(robotInterface->hardware()->robotInformations()._identifier)
		);
		robot->_x = robotInterface->hardware()->position().x();
		robot->_y = robotInterface->hardware()->position().y();
		robot->_mass = robotInterface->hardware()->robotInformations()._mass;
		robot->_length = robotInterface->hardware()->robotInformations()._dimensions[0];
		robot->_width = robotInterface->hardware()->robotInformations()._dimensions[1];
		robot->_height = robotInterface->hardware()->robotInformations()._dimensions[2];
		robot->_simubot = robotInterface;
		this->m_robots.insert(robot);
		emit this->displayRobot(*robot);
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::robot