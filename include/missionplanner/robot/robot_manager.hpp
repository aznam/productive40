/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the model of a robot.
 * \details This file provides the model of a robot.
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
#include <set>
#include <string>

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtCore/QObject>

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <common/pattern/singleton.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "robot_model.hpp"
#include "../application/robot/simubot_interface.hpp"

namespace lis::pecase::productive40::missionplanner::robot {

#pragma region Types Definitions

	/**
	 * \class RobotManager include/missionplanner/robot/robot_manager.hpp \
	 * <productive40/missionplanner/robot/robot_manager.hpp>
	 * \brief Robot Manager.
	 * \details This class defines a RobotManager which handles operation related to robots.
	 * \nosubgrouping
	 */
	class RobotManager :
		public QObject,
		public common::pattern::Singleton<RobotManager> {

		friend class common::pattern::Singleton<RobotManager>;

		Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Set of robots.
		 * \details Set of robots.
		 */
		private:
		std::set<RobotModel *>
		m_robots;

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
		RobotManager (
			void
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		private:
		~RobotManager (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robots Management
	 */
	#pragma region Robots Management
	/**@{*/

		#pragma region Signals

		/**
		 * \brief Emitted when a robot is connected.
		 * \details Emitted when a robot is connected.
		 * \param[in] robot_model (const RobotModel &) Reference to the robot.
		 */
		signals:
		void
		displayRobot (
			const RobotModel &
		);

		#pragma endregion

		#pragma region Instance Methods

		/**
		 * \brief Called when a robot is connected.
		 * \details Called when a robot is connected.
		 */
		public:
		void
		robotConnected (
			application::robot::SimubotInterface *
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class RobotManager

#pragma endregion;

} // lis::pecase::productive40::missionplanner::robot