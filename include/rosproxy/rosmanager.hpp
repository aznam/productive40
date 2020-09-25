#pragma once

#include <string>
#include <common/pattern/singleton.hpp>
#include <ros/ros.h>
#include "rosproxy_defines.hpp"

namespace lis::pecase::productive40::rosproxy {

	class ROSPROXY_LIB ROSManager :
		public common::pattern::Singleton<ROSManager> {

		friend class common::pattern::Singleton<ROSManager>;

		/*private:
		ros::NodeHandle
		m_nodeHandle;*/

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

	}; // class ROSInterface

}; // namespace lis::pecase::productive40::rosproxy