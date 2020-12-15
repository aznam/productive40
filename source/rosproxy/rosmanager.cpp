#pragma once

#include "../../include/rosproxy/rosmanager.hpp"

#include <geometry_msgs/Twist.h>


namespace lis::pecase::productive40::rosproxy {

	const char * Environment_Topic = "/robots/broadcast";

	ROSManager::ROSManager (
		void
	) :
		common::pattern::Singleton<ROSManager>(),
		m_nodeHandle(nullptr) {
	}

	ROSManager::~ROSManager (
		void
	) {
		this->close();
	}

	void
	ROSManager::init (
		int argc,
		char ** argv,
		const std::string & node_name
	) {
		ros::init(argc, argv, node_name.c_str());
		this->m_nodeHandle = new ros::NodeHandle;
	}

	void
	ROSManager::close (
		void
	) {
		_publishers.clear();
		delete this->m_nodeHandle;
	}

	void
	ROSManager::subscribeBroadcast (
		void
	) {
		/*this->m_broadcastSubscriber = this->m_nodeHandle.subscribe(
			Environment_Topic,
			1000
		);*/
	}

	void
	ROSManager::commandVelocity(
		const std::string & robot_name,
		double x,
		double y,
		double theta
	) {
		if(this->m_nodeHandle == nullptr) return;
		std::string cmd_vel = std::string("/cmd_vel_") + robot_name;
		::ros::Publisher publisher;
		if(_publishers.find(cmd_vel) == _publishers.end())
			_publishers[cmd_vel] = this->m_nodeHandle->advertise<geometry_msgs::Twist>(cmd_vel, 10000);
			
		geometry_msgs::Twist msg;
		msg.angular.x = 0.0;
		msg.angular.y = 0.0;
		msg.angular.z = theta;
		msg.linear.x = x;
		msg.linear.y = y;
		msg.linear.z = 0.0;

		_publishers[cmd_vel].publish(msg);
	}

}; // namespace lis::pecase::productive40::rosproxy