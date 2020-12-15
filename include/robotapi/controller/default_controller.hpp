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
	Standard Includes
===================================================================================================
*/
#include <stack>
#include <tuple>

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <common/pattern/generic_fsm.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../robotapi_defines.hpp"
#include "controller_interface.hpp"
#include "../hardware.hpp"

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

	#pragma region Nested Types Definitions

		/**
		 * \class BaseState include/robotapi/controller/default_controller.hpp \
		 * <productive40/robotapi/controller/default_controller.hpp>
		 * \brief Base State of the Default controller.
		 * \details Base State of the Default controller.
		 * \nosubgrouping
		 */
		protected:
		class BaseState :
			public DefaultController::State {

		/**
		 * \name Instance Data Members
		 */
		#pragma region Instance Data Members
		/**@{*/

			/**
			 * \brief Max duration of the state (in msec).
			 * \details Max duration of the state (in msec).
			 */
			protected:
			double
			m_maxDuration;

			/**
			 * \brief Expected robot start state.
			 * \details Expected robot start state (t, v, d).
			 */
			protected:
			std::tuple<double, double, double>
			m_start;

			/**
			 * \brief Expected robot end state.
			 * \details Expected robot end state (t, v, d).
			 */
			protected:
			std::tuple<double, double, double>
			m_end;

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
			 * \param[in] context (const Context &) Reference to the parent machine.
			 */
			public:
			BaseState (
				DefaultController &
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brief Default dtor.
			 * \details Default destructor.
			 */
			public: virtual
			~BaseState (
				void
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		/**
		 * \name Time Management
		 */
		#pragma region Time Management
		/**@{*/

			#pragma region Instance Methods

			/**
			 * \brief Set maximum duration.
			 * \details Set the maximum duration (in msec).
			 * \param[in] max_duration (double) Maximum duration (in msec).
			 */
			public:
			void
			setMaxDuration (
				double
			);

			/**
			 * \brief Returns the maximum duration.
			 * \details Returns the maximum duration.
			 * \return (double) The maximum duration of the state (in msec).
		 	 */
			public:
			double
			getMaxDuration (
				void
			) const;

			/**
			 * \brief Set start state.
			 * \details Set start state
			 * \param[in] t (double) Start date.
			 * \param[in] v (double) Initial speed.
			 * \param[in] p (double) Initial distance.
			 */
			public:
			void
			setStartState (
				double,
				double,
				double
			);

			/**
			 * \brief Set end state.
			 * \details Set end state.
			 * \param[in] t (double) End date.
			 * \param[in] v (double) Final speed.
			 * \param[in] p (double) Final distance.
			 */
			public:
			void
			setEndState (
				double,
				double,
				double
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		/**
		 * \name Command Operations
		 */
		#pragma region Command Operations
		 /**@{*/

			#pragma region Instance Methods

			/**
			 * \brief Compute the command law.
			 * \details Compute the command law.
			 * \param[in] at (double) Value of the acceleration (in m.sec-2).
			 * \param[in] vt (double) Value of the velocity (in m.sec-1).
			 * \param[in] pt (double) Distance from the initial point (in m).
			 */
			protected:
			void
			computeCommand (
				double,
				double,
				double
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		}; // class BaseState

		/**
		 * \class IdleState include/robotapi/controller/default_controller.hpp \
		 * <productive40/robotapi/controller/default_controller.hpp>
		 * \brief Idle State of the Default controller.
		 * \details Idle State of the Default controller.
		 * \nosubgrouping
		 */
		protected:
		class IdleState :
			public BaseState {

		/**
		 * \name Constructors / Destructor
		 */
		#pragma region Constructors / Destructor
		/**@{*/

			#pragma region Constructors

			/**
			 * \brief Default ctor.
			 * \details Default constructor.
			 * \param[in] context (const Context &) Reference to the parent machine.
			 */
			public:
			IdleState (
				DefaultController &
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brief Default dtor.
			 * \details Default destructor.
			 */
			public:
			~IdleState (
				void
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		/**
		 * \name State Operations
		 */
		#pragma region State Operations
		/**@{*/

			#pragma region Implemented Methods

			/**
			 * \brief Called when entering the state.
			 * \details This method is called when the machine enters the state.
			 */
			protected:
			void
			enter (
				void
			) override;

			/**
			 * \brief Called when updating the machine.
			 * \details This method is called when the message is updating.
			 */
			protected:
			void
			update (
				void
			) override;

			/**
			 * \brief Called when leaving the state.
			 * \details This method is called when the machine leaves the state.
			 */
			protected:
			void
			exit (
				void
			) override;

			#pragma endregion

		/**@}*/
		#pragma endregion

		}; // class IdleState

		/**
		 * \class PrepareState include/robotapi/controller/default_controller.hpp \
		 * <productive40/robotapi/controller/default_controller.hpp>
		 * \brief Preparation State of the Default controller.
		 * \details Preparation State of the Default controller.
		 * \nosubgrouping
		 */
		protected:
		class PrepareState :
			public BaseState {

		/**
		 * \name Constructors / Destructor
		 */
		#pragma region Constructors / Destructor
		/**@{*/

			#pragma region Constructors

			/**
			 * \brief Default ctor.
			 * \details Default constructor.
			 * \param[in] context (const Context &) Reference to the parent machine.
			 */
			public:
			PrepareState (
				DefaultController &
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brief Default dtor.
			 * \details Default destructor.
			 */
			public:
			~PrepareState (
				void
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		/**
		 * \name State Operations
		 */
		protected:
		#pragma region State Operations
		/**@{*/

			#pragma region Implemented Methods

			/**
			 * \brief Called when entering the state.
			 * \details This method is called when the machine enters the state.
			 */
			protected:
			void
			enter (
				void
			) override;

			/**
			 * \brief Called when updating the machine.
			 * \details This method is called when the message is updating.
			 */
			protected:
			void
			update (
				void
			) override;

			/**
			 * \brief Called when leaving the state.
			 * \details This method is called when the machine leaves the state.
			 */
			protected:
			void
			exit (
				void
			) override;

			#pragma endregion

		/**@}*/
		#pragma endregion

		}; // class PrepareState

		/**
		 * \class AccelState include/robotapi/controller/default_controller.hpp \
		 * <productive40/robotapi/controller/default_controller.hpp>
		 * \brief Accel State of the Default controller.
		 * \details Accel State of the Default controller.
		 * \nosubgrouping
		 */
		protected:
		class AccelState :
			public BaseState {

		/**
		 * \name Constructors / Destructor
		 */
		#pragma region Constructors / Destructor
		/**@{*/

			#pragma region Constructors

			/**
			 * \brief Default ctor.
			 * \details Default constructor.
			 * \param[in] context (const Context &) Reference to the parent machine.
			 */
			public:
			AccelState (
				DefaultController &
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brief Default dtor.
			 * \details Default destructor.
			 */
			public:
			~AccelState (
				void
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		/**
		 * \name State Operations
		 */
		#pragma region State Operations
		/**@{*/

			#pragma region Implemented Methods

			/**
			 * \brief Called when entering the state.
			 * \details This method is called when the machine enters the state.
			 */
			protected:
			void
			enter (
				void
			) override;

			/**
			 * \brief Called when updating the machine.
			 * \details This method is called when the message is updating.
			 */
			protected:
			void
			update (
				void
			) override;

			/**
			 * \brief Called when leaving the state.
			 * \details This method is called when the machine leaves the state.
			 */
			protected:
			void
			exit (
				void
			) override;

			#pragma endregion

		/**@}*/
		#pragma endregion

		}; // class AccelState

		/**
		 * \class CruiseState include/robotapi/controller/default_controller.hpp \
		 * <productive40/robotapi/controller/default_controller.hpp>
		 * \brief Cruise State of the Default controller.
		 * \details Cruise State of the Default controller.
		 * \nosubgrouping
		 */
		protected:
		class CruiseState :
			public BaseState {

		/**
		 * \name Constructors / Destructor
		 */
		#pragma region Constructors / Destructor
		/**@{*/

			#pragma region Constructors

			/**
			 * \brief Default ctor.
			 * \details Default constructor.
			 * \param[in] context (const Context &) Reference to the parent machine.
			 */
			public:
			CruiseState (
				DefaultController &
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brief Default dtor.
			 * \details Default destructor.
			 */
			public:
			~CruiseState (
				void
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		/**
		 * \name State Operations
		 */
		#pragma region State Operations
		/**@{*/

			#pragma region Implemented Methods

			/**
			 * \brief Called when entering the state.
			 * \details This method is called when the machine enters the state.
			 */
			protected:
			void
			enter (
				void
			) override;

			/**
			 * \brief Called when updating the machine.
			 * \details This method is called when the message is updating.
			 */
			protected:
			void
			update (
				void
			) override;

			/**
			 * \brief Called when leaving the state.
			 * \details This method is called when the machine leaves the state.
			 */
			protected:
			void
			exit (
				void
			) override;

			#pragma endregion

		/**@}*/
		#pragma endregion

		}; // class CruiseState

		/**
		 * \class DeccelState include/robotapi/controller/default_controller.hpp \
		 * <productive40/robotapi/controller/default_controller.hpp>
		 * \brief Deccel State of the Default controller.
		 * \details Deccel State of the Default controller.
		 * \nosubgrouping
		 */
		protected:
		class DeccelState :
			public BaseState {

		/**
		 * \name Constructors / Destructor
		 */
		#pragma region Constructors / Destructor
		/**@{*/

			#pragma region Constructors

			/**
			 * \brief Default ctor.
			 * \details Default constructor.
			 * \param[in] context (const Context &) Reference to the parent machine.
			 */
			public:
			DeccelState (
				DefaultController &
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brief Default dtor.
			 * \details Default destructor.
			 */
			public:
			~DeccelState (
				void
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		/**
		 * \name State Operations
		 */
		#pragma region State Operations
		/**@{*/

			#pragma region Implemented Methods

			/**
			 * \brief Called when entering the state.
			 * \details This method is called when the machine enters the state.
			 */
			protected:
			void
			enter (
				void
			) override;

			/**
			 * \brief Called when updating the machine.
			 * \details This method is called when the message is updating.
			 */
			protected:
			void
			update (
				void
			) override;

			/**
			 * \brief Called when leaving the state.
			 * \details This method is called when the machine leaves the state.
			 */
			protected:
			void
			exit (
				void
			) override;

			#pragma endregion

		/**@}*/
		#pragma endregion

		}; // class DeccelState

		/**
		 * \enum StateIdentifier
		 * \brief State Identification Enumeration.
		 * \details State Identification Enumeration.
		 */
		protected:
		enum StateIdentifier {

			/**
			 * \brief Idle state.
			 * \details Idle state
			 */
			IDLE = 0,

			/**
			 * \brief Prepare state.
			 * \details Prepare state.
			 */
			PREPARE = 1,

			/**
			 * \brief Accel state.
			 * \details Accel state.
			 */
			ACCEL = 2,

			/**
			 * \brief Cruise state.
			 * \details Cruise state.
			 */
			CRUISE = 3,

			/**
			 * \brief Deccel state.
			 * \details Deccel state.
			 */
			DECCEL = 4,

			/**
			 * \brief Number of states.
			 * \details Number of states.
			 */
			 COUNT

		}; // enum StateIdentifier

	#pragma endregion

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Elapsed time.
		 * \details Elapsed time.
		 */
		private:
		double
		m_elapsedTime;

		/**
		 * \brief Stack of states.
		 * \details Stack of states.
		 */
		private:
		std::stack<BaseState *>
		m_statesStack;

		/**
		 * \brief Reference to the hardware interface.
		 * \details Reference to the hardware interface.
		 */
		private:
		hardware::HardwareInterface &
		m_hardware;

		/**
		 * \brief Trajectory points.
		 * \details Trajectory points.
		 */
		private:
		std::vector<Eigen::Vector2d>
		m_trajectoryPoints;

		/**
		 * \brief Initial position.
		 * \details Initial position.
		 */
		private:
		Eigen::Vector2d
		m_source;

		/**
		 * \brief Destination position.
		 * \details Destination position.
		 */
		private:
		Eigen::Vector2d
		m_destination;

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
	 * \name Robot Manipulation & Handling
	 */
	#pragma region Robot Manipulation & Handling
	/**@{*/

		#pragma region Implemented Methods

		/**
		 * \brief State checking.
		 * \details Check the transitions conditions.
		 * \param[in] t (double) Elapsed time since the last update. 
		 */
		private:
		void
		stateCheck (
			double
		);

		/**
		 * \brief Update the controller.
		 * \details Update the controller.
		 * \param[in] t (double) Elapsed time since the last update.
		 */
		public:
		void
		update (
			double
		) override;

		/**
		 * \brief Ask the robot to travel.
		 * \details Ask the robot to travel.
		 */
		public:
		void
		startTravel (
			void
		) override;

		/**
		 * \brief Ask the robot to stop travel.
		 * \details Ask the robot to stop travel.
		 */
		public:
		void
		stopTravel (
			void
		) override;

		/**
		 * \brief Returns basic informations about the robot.
		 * \details Returns basic informations about the robot.
		 * \returns (const hardware::RobotInformation &) Informations about the robot.
		 */
		public:
		const hardware::RobotInformation &
		robotInformations (
			void
		) const override;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Trajectory Management
	 */
	#pragma region Trajectory Management
	/**@{*/

		#pragma region Implemented Methods

		/**
		 * \brief Compute the trajectory profile to a destination point.
		 * \details Compute the trajectory profile to a destination point.
		 * \param[in] initial_point (const Eigen::Vector2d &) Initial point.
		 * \param[in] final_point (const Eigen::Vector2d &) Destination point.
		 */
		public:
		void
		computeTrajectoryProfile (
			const Eigen::Vector2d &,
			const Eigen::Vector2d &
		);

		/**
		 * \brief Set a trajectory for the robot.
		 * \details Set a trajectory for the robot.
		 * \param[in] trajectory (const std::vector<Eigen::Vector2d> &) Set of trajectory points.
		 */
		public:
		void
		setTrajectory (
			const std::vector<Eigen::Vector2d> &
		) override;

		/**
		 * \brief Returns the target orientation.
		 * \details Returns the target orientation.
		 * \return (double) The target orientation (in radians).
		 */
		public:
		double
		targetOrientation (
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