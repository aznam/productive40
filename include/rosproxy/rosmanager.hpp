/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an interface for the ROS Manager.
 * \details This file provides an interface for the ROS Manager.
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
#include <string>
#include <functional>

/*
===================================================================================================
	ROS Includes
===================================================================================================
*/
#include <ros/ros.h>

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
#include "rosproxy_defines.hpp"

namespace lis::pecase::productive40::rosproxy {

	
	class ROSPROXY_LIB ROSManager :
		public common::pattern::Singleton<ROSManager> {

		friend class common::pattern::Singleton<ROSManager>;

		private:
		ros::NodeHandle *
		m_nodeHandle;

		std::map<std::string, ::ros::Publisher> _publishers;

		private:
		ros::Subscriber
		m_broadcastSubscriber;

		private:
		ROSManager (
			void
		);

		private:
		~ROSManager (
			void
		);

		public: void
		init (
			int,
			char **,
			const std::string &
		);

		public: void
		close (
			void
		);

		public: void
		subscribeBroadcast (
			void
		);

		public: void
		commandVelocity(
			const std::string & robot_name,
			double x,
			double y,
			double theta
		);


	}; // class ROSInterface

}; // namespace lis::pecase::productive40::rosproxy