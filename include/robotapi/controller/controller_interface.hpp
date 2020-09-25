/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an interface for Robot Controller.
 * \details This file provides an interface to control the robot.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../robotapi_defines.hpp"
#include "../hardware/robot_information.hpp"
#include <Eigen/Dense>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::controller {
	
#pragma region Types Definitions

	/**
	 * \interface ControllerInterface include/robotapi/controller/controller_interface.hpp \
	 * <productive40/robotapi/controller/controller_interface.hpp>
	 * \brief Interface to control the robot.
	 * \details This interface provides generic routines to control the robot. Subclass this
	 * interface to implement control algorithms.
	 * \nosubgrouping
	 */
	class ROBOTAPI_LIB ControllerInterface {

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
		ControllerInterface (
			void
		) = default;

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public: virtual
		~ControllerInterface (
			void
		) = default;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot Manipulation
	 */
	#pragma region Robot Manipulation
	/**@{*/

		#pragma region Abstract Methods

		/**
		 * \brief Returns basic informations about the robot.
		 * \details Returns basic informations about the robot.
		 * \returns (const hardware::RobotInformation &) Informations about the robot.
		 */
		 public: virtual
		 const hardware::RobotInformation &
		 robot_informations (
			void
		 ) const = 0;

		 public: virtual
		 void
		 setTrajectory (
			const std::vector<Eigen::Vector2d> &
		 ) = 0;

		 public: virtual
		 void
		 update (
			double
		 ) = 0;

		 public: virtual
		 void
		 startTravel (
			void
		 ) = 0;

		 public: virtual
		 void
		 stopTravel (
			void
		 ) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class ControllerInterface

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::controller

/*
===================================================================================================
    Macros
===================================================================================================
*/