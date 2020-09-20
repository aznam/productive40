/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Generic Finite State Machine Interface.
 * \details This file provides an interface for generic finite state machines.
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
#include <vector>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::pattern {

#pragma region Types Definitions

	/**
	 * \class GenericFSM include/common/pattern/generic_fsm.hpp \
	 * <productive40/common/pattern/generic_fsm.hpp>
	 * \brief Generic Implementation of Finite State Machines.
	 * \details This template class turns any Context class into Finite State Machine.
	 *
	 * The states are stored using an integer index, and added in the order of insertion (FIFO).
	 *
	 * Example of real implementation:
	 * \snippet example/fsm_example.hpp GenericFSM Implementation
	 * \tparam Context Class to turn into a FSM.
	 * \nosubgrouping
	 */
	template <
		typename Context
	> class GenericFSM {

	/**
	 * \name Nested Types
	 */
	#pragma region Nested Types
	/**@{*/

		/**
		 * \class State include/common/pattern/generic_fsm.hpp \
		 * <productive40/common/pattern/generic_fsm.hpp>
		 * \brief Base class for Generic State.
		 * \details Subclass this interface to create a state usable by a generic finite state
		 * machine.
		 * \nosubgrouping
		 */
		protected:
		class State {

			friend class GenericFSM<Context>;

		/**
		 * \name Instance Data Members
		 */
		#pragma region Instance Data Members
		/**@{*/

			/**
			 * \brief The context of the state.
			 * \details Reference to the context of this state.
			 */
			protected:
			Context &
			m_context;

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
			protected:
			State (
				const Context &
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brief Virtual dtor.
			 * \details Virtual destructor.
			 */
			protected: virtual
			~State (
				void
			) = 0;

			#pragma endregion

		/**@}*/
		#pragma endregion

		/**
		 * \name State Operations
		 */
		#pragma region State Operations
		/**@{*/

			#pragma region Abstract Methods

			/**
			 * \brief Called when entering the state.
			 * \details This method is called when the machine enters the state.
			 */
			protected: virtual
			void
			enter (
				void
			) = 0;

			/**
			 * \brief Called when updating the machine.
			 * \details This method is called when the message is updating.
			 */
			protected: virtual
			void
			update (
				void
			) = 0;

			/**
			 * \brief Called when leaving the state.
			 * \details This method is called when the machine leaves the state.
			 */
			protected: virtual
			void
			exit (
				void
			) = 0;

			#pragma endregion

		/**@}*/
		#pragma endregion

		}; // class GenericFSM<Context>::State

	/**@}*/
	#pragma endregion

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief List of states.
		 * \details List of the states.
		 */
		protected:
		std::vector<State *>
		m_states;

		/**
		 * \brief Current state.
		 * \details Current state.
		 */
		protected:
		State *
		m_currentState;

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
		 */
		protected:
		GenericFSM (
			void
		);

		#pragma endregion

		#pragma endregion Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 * \remarks The destructor destroys the instance of registered states. Do not destroy them
		 * manually.
		 */
		protected: virtual
		~GenericFSM (
			void
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name States Management
	 */
	#pragma region States Management
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Add a state.
		 * \details Add a state to the list of state.
		 * \param[in] state (const State *) State to add to the machine.
		 */
		public:
		void
		addState (
			const State *
		);

		/**
		 * \brief Remove a state.
		 * \details Remove a state from the list of state.
		 * \param[in] index (unsigned int) Index of the state to remove from the machine.
		 */
		public:
		void
		removeState (
			unsigned int
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Machine Management
	 */
	#pragma region Machine Management
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Change the state of the machine.
		 * \details This method asks the machine to enter a new state.
		 * \param[in] index (unsigned int) Index of the next state.
		 */
		public:
		void
		changeState (
			unsigned int
		);

		/**
		 * \brief Update the machine.
		 * \details This method updates the current machine state.
		 * \note This method can simulate a state re-entry from the current state.
		 * \image html fsm.png "Simulation of state re-entry."
		 */
		public:
		void
		update (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class GenericFSM<Context>

#pragma endregion

}; // namespace lis::pecase::productive40::common::pattern

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "generic_fsm.tpp"