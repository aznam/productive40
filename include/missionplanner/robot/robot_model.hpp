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
#include <string>

/*
===================================================================================================
	Framework Includes
===================================================================================================
*/
#include <types.hpp>

#include "../application/robot/simubot_interface.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::robot {
     
#pragma region Types Definitions

	/**
	 * \struct RobotModel include/missionplanner/robot/robot_model.hpp \
	 * <productive40/missionplanner/robot/robot_model.hpp>
	 * \brief Robot Model.
	 * \details This structure represents a robot and holds data concernig a robot.
	 * \nosubgrouping
	 */
    struct RobotModel {

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		public:
		application::robot::SimubotInterface * _simubot;

		/**
		 * \brief Vendor name.
		 * \details Vendor name.
		 */
		public:
		std::string
		_vendorName;

		/**
		 * \brief identifier.
		 * \details identifier.
		 */
		public:
		std::string
		_identifier;

		/**
		 * \brief Length.
		 * \details Length.
		 */
		public:
		double
		_length;

		/**
		 * \brief Width.
		 * \details Width.
		 */
		public:
		double
		_width;

		/**
		 * \brief Height.
		 * \details Height.
		 */
		public:
		double
		_height;

		/**
		 * \brief Base Mass.
		 * \details Base Mass (in kilograms).
		 */
		public:
		double
		_mass;

		/**
		 * \brief Maximum linear speed.
		 * \details Maximum linear speed (in m.s-1).
		 */
		public:
		double
		_maxLinearSpeed;

		/**
		 * \brief Maximum linear acceleration.
		 * \details Maximum linear acceleration (in m.s-2).
		 */
		public:
		double
		_maxLinearAccel;

		/**
		 * \brief Current linear speed.
		 * \details Current linear speed (in m.s-1).
		 */
		public:
		double
		_curLinearSpeed;

		/**
		 * \brief Current linear acceleration.
		 * \details Current linear acceleration (in m.s-2).
		 */
		public:
		double
		_curLinearAccel;

		/**
		 * \brief Current X position.
		 * \details Current X position.
		 */
		public:
		double
		_x = 0;

		/**
		 * \brief Current Y position.
		 * \details Current Y position.
		 */
		public:
		double
		_y = 0;

	/**@}*/
    #pragma endregion

    }; // struct RobotModel

	/**
	 * \brief Alias for struct RobotModel.
	 * \details Alias for struct RobotModel.
	 */
	typedef struct RobotModel RobotModel;

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::robot