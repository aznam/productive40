/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide a default controller.
 * \details This file provides the interface of the default controller
 * (Mellah et al., 4-mecanum wheeled mobile robot actuator fault detection & isolation
 *  using unknown input observer-based approach, 2020).
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
#include "controller_interface.hpp"
#include "../hardware/hardware_interface.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::robotapi::controller {
	
#pragma region Types Definitions

	/**
	 * \class DefaultController include/robotapi/controller/default_controller.hpp \
	 * <productive40/robotapi/controller/default_controller.hpp>
	 * \brief Default controller.
	 * \details Default controller implented using the algorithm of Mellah et al.,
	 * 4-mecanum wheeled mobile robot actuator fault detection & isolation
	 *  using unknown input observer-based approach, 2020.
	 * \nosubgrouping
	 */
	class ROBOTAPI_LIB DefaultController :
		public ControllerInterface {

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Robot informations.
		 * \details Base informations about the robot.
		 */
		private:
		const hardware::RobotInformation
		m_robotInformations;

	/**@}*/
	#pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Constructors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 * \param[in] hw_interface (const hardware::HardwareInterface &) Interface to the hardware.
		 */
		public:
		DefaultController (
			 const hardware::HardwareInterface &
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~DefaultController (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot Manipulation
	 */
	#pragma region Robot Manipulation
	/**@{*/

		#pragma region Implemented Methods

		/**
		 * \brief Returns basic informations about the robot.
		 * \details Returns basic informations about the robot.
		 * \returns (const hardware::RobotInformation &) Informations about the robot.
		 */
		 public:
		 const hardware::RobotInformation &
		 robot_informations (
			void
		 ) const override;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class DefaultController

#pragma endregion

}; // namespace lis::pecase::productive40::robotapi::controller

/*
===================================================================================================
    Macros
===================================================================================================
*/