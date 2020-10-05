/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an interface for Hardware access.
 * \details This file provides an interface to access the hardware of the robot.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Eigen Includes
===================================================================================================
*/
#include <Eigen/Dense>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../robotapi_defines.hpp"
#include "robot_information.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::hardware {
	
#pragma region Types Definitions

	/**
	 * \interface HardwareInterface include/robotapi/hardware/hardware_interface.hpp \
	 * <productive40/robotapi/hardware/hardware_interface.hpp>
	 * \brief Interface to access the hardware of the robot.
	 * \details This interface provides generic access to the hardware. Subclass this
	 * interface to implement specific hardware access.
	 * \nosubgrouping
	 */
	class ROBOTAPI_LIB HardwareInterface {

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
		protected:
		HardwareInterface (
			void
		) = default;

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public: virtual
		~HardwareInterface (
			void
		) = default;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot Information Management
	 */
	#pragma region Robot Informations Management
	/**@{*/

		#pragma region Abstract Getters

		/**
		 * \brief Returns basic informations about the robot.
		 * \details Returns basic informations stored in the robot.
		 * \returns (const hardware::RobotInformation &) Informations about the robot.
		 */
		public: virtual
		const RobotInformation &
		robotInformations (
		void
		) const = 0;

		/**
		 * \brief Returns the position of the robot.
		 * \details Returns the position of the robot.
		 * \returns (Eigen::Vector2d) Position of the robot.
		 */
		public: virtual
		Eigen::Vector2d
		position (
			void
		) const = 0;

		/**
		 * \brief Returns the orientation of the robot.
		 * \details Returns the orientation of the robot.
		 * \returns (double) Orientation of the robot (in radians).
		 */
		public: virtual
		double
		orientation (
			void
		) const = 0;

		/**
		 * \brief Returns the velocity of the robot.
		 * \details Returns the velocity of the robot.
		 * \returns (Eigen::Vector2d) Velocity vector.
		 */
		public: virtual
		Eigen::Vector2d
		velocity (
			void
		) const = 0;

		/**
		 * \brief Returns the angular speed.
		 * \details Returns the angular speed of the robot.
		 * \returns (double) Angular speed (in radians.s-1).
		 */
		public: virtual
		double
		angularSpeed (
			void
		) const = 0;

		/**
		 * \brief Returns the acceleration of the robot.
		 * \details Returns the acceleration of the robot.
		 * \returns (Eigen::Vector2d) Acceleration vector.
		 */
		public: virtual
		Eigen::Vector2d
		acceleration (
			void
		) const = 0;

		/**
		 * \brief Returns the angular acceleration.
		 * \details Returns the angular acceleration of the robot.
		 * \returns (double) Angular acceleration (in radians.s-2).
		 */
		public: virtual
		double
		angularAcceleration (
			void
		) const = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Harware Managements
	 */
	#pragma region Hardware Management
	/**@{*/

		#pragma region Abstract Methods

		/**
		 * \brief Send a command to the robot.
		 * \details Send a wheel command to control the robot.
		 * \param[in] command (const std::vector<double> &) List of command.
		 */
		public: virtual
		void
		wheelCommand (
			const std::vector<double> &
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class HardwareInterface

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::hardware