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

#include <common/pattern/generic_fsm.hpp>

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
		public ControllerInterface,
		public common::pattern::GenericFSM<DefaultController> {

		class BaseState :
			public DefaultController::State {

			protected:
			double
			m_maxTime;

			protected:
			double
			m_currentTime;

			public:
			BaseState (
				DefaultController &
			);

			public:
			void
			setMaxTime (
				double
			);

			protected:
			void
			computeCommand (
				double,
				double,
				double
			);

		};

		class IdleState :
			public BaseState {

			public:
			IdleState (
				DefaultController &
			);

			protected:
			void
			enter (
				void
			) override;

			protected:
			void
			update (
				void
			) override;

			protected:
			void
			exit (
				void
			) override;

		};

		class PrepareState :
			public BaseState {

			public:
			PrepareState (
				DefaultController &
			);

			protected:
			void
			enter (
				void
			) override;

			protected:
			void
			update (
				void
			) override;

			protected:
			void
			exit (
				void
			) override;

		};

		class AccelState :
			public BaseState {

			public:
			AccelState (
				DefaultController &
			);

			protected:
			void
			enter (
				void
			) override;

			protected:
			void
			update (
				void
			) override;

			protected:
			void
			exit (
				void
			) override;

		};

		class CruiseState :
			public BaseState {

			public:
			CruiseState (
				DefaultController &
			);

			protected:
			void
			enter (
				void
			) override;

			protected:
			void
			update (
				void
			) override;

			protected:
			void
			exit (
				void
			) override;

		};

		class DeccelState :
			public BaseState {

			public:
			DeccelState (
				DefaultController &
			);

			protected:
			void
			enter (
				void
			) override;

			protected:
			void
			update (
				void
			) override;

			protected:
			void
			exit (
				void
			) override;

		};

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

		private:
		hardware::HardwareInterface &
		m_hardware;

		private:
		std::vector<Eigen::Vector2d>
		m_trajectoryPoints;

		private:
		Eigen::Vector2d
		m_initialPosition;

		private:
		Eigen::Vector2d
		m_destination;

		private:
		double
		m_refreshTime;

		private:
		double
		m_elapsedTime;

		private:
		double
		m_profile [5];



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

		 public: virtual
		 void
		 setTrajectory (
			const std::vector<Eigen::Vector2d> &
		 ) override;

		 public: virtual
		 void update (
			double
		 ) override;

		 public: virtual
		 void startTravel (
			void
		 ) override;

		 public: virtual
		 void stopTravel (
			void
		 ) override;

		 public:
		 void
		 setTimeMax (
			unsigned int,
			double
		 );

		 private:
		 double
		 coeffA (
			void
		 ) const;

		 private:
		 double
		 coeffB (
			void
		 ) const;

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