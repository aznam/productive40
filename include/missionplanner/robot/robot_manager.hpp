#pragma once

#include <map>
#include <string>
#include <common/pattern/singleton.hpp>

namespace lis::pecase::productive40::missionplanner::robot {

#pragma region Types Definitions

	class RobotManager :
		public common::pattern::Singleton<RobotManager> {

		friend class common::pattern::Singleton<RobotManager>;

	#pragma region Constructors / Destructor

		#pragma region Constructors

		private:
		RobotManager (
			void
		) = default;

		#pragma endregion

		#pragma region Destructor

		private:
		~RobotManager (
			void
		) = default;

		#pragma endregion

	#pragma endregion

	};

#pragma endregion;

} // lis::pecase::productive40::missionplanner::robot