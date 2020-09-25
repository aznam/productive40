#pragma once

#include <robotapi/hardware/robot_information.hpp>

namespace lis::pecase::productive40::missionplanner::robot {

#pragma region Types Definitions

	class Robot {

		private:
		robotapi::hardware::RobotInformation *
		m_informations;

	};

#pragma endregion;

} // lis::pecase::productive40::missionplanner::robot