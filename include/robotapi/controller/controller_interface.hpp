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
#include "../hardware.hpp"

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
		 robotInformations (
			void
		 ) const = 0;

		 /**
		  * \brief Update the controller.
		  * \details Update the controller.
		  * \param[in] t (double) Elapsed time since the last update.
		  */
		 public: virtual
		 void
		 update (
			double
		 ) = 0;

		 /**
		  * \brief Ask the robot to travel.
		  * \details Ask the robot to travel.
		  */
		 public: virtual
		 void
		 startTravel (
			void
		 ) = 0;

		  /**
		  * \brief Ask the robot to stop travel.
		  * \details Ask the robot to stop travel.
		  */
		 public: virtual
		 void
		 stopTravel (
			void
		 ) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Trajectory Management
	 */
	#pragma region Trajectory Management
	/**@{*/

		#pragma region Abstract Methods

		 /**
		  * \brief Set a trajectory for the robot.
		  * \details Set a trajectory for the robot.
		  * \param[in] trajectory (const std::vector<Eigen::Vector2d> &) Set of trajectory points.
		  */
		public: virtual
		void
		setTrajectory (
			const std::vector<Eigen::Vector2d> &
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class ControllerInterface

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::controller