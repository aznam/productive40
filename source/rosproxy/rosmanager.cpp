#pragma once

#include "../../include/rosproxy/rosmanager.hpp"

namespace lis::pecase::productive40::rosproxy {

	const char * Environment_Topic = "/robots/discovery";

	ROSManager::ROSManager (
		void
	) :
		common::pattern::Singleton<ROSManager>() {
	}

	ROSManager::~ROSManager (
		void
	) {
	}

	void
	ROSManager::init (
		int argc,
		char ** argv,
		const std::string & node_name
	) {
		ros::init(argc, argv, node_name.c_str());
	}

}; // namespace lis::pecase::productive40::rosproxy