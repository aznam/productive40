/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Generic Finite State Machine Implementation.
 * \details This file provides an implementation for generic finite state machines.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "generic_fsm.hpp"
#include <cassert>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::pattern {

#pragma region Constructors / Destructor

	#pragma region GenericFSM::State

	template <
		typename Context
	> GenericFSM<Context>::State::State (
		const Context & context
	) :
		m_context(const_cast<Context &>(context)) {
	}

	template <
		typename Context
	> GenericFSM<Context>::State::~State (
		void
	) {
	}

	#pragma endregion

	#pragma region GenericFSM

	template <
		typename Context
	> GenericFSM<Context>::GenericFSM (
		void
	) :
		m_currentState(nullptr),
		m_nextState(nullptr),
		m_states(std::vector<GenericFSM<Context>::State *>()) {
	}

	template <
		typename Context
	> GenericFSM<Context>::~GenericFSM (
		void
	) {
		for(auto iter = m_states.begin(); iter < m_states.end(); iter++) {
			delete *iter;
		}
		m_states.clear();
	}

	#pragma endregion
	
#pragma endregion

#pragma region Functions Definitions & Implementations

	#pragma region States Management

	template <
		typename Context
	> void
	GenericFSM<Context>::addState (
		const State * state
	) {
		m_states.push_back(const_cast<State*>(state));
	}

	template <
		typename Context
	> void
	GenericFSM<Context>::removeState (
		unsigned int index
	) {
		assert(index < m_states.size());
		auto iterator = m_states.begin() + index;
		m_states.erase(iterator);
	}

	#pragma endregion

	#pragma region Machine Management

	template <
		typename Context
	> void
	GenericFSM<Context>::changeState (
		unsigned int index
	) {
		assert(index < m_states.size());
		m_nextState = m_states[index];
	}

	template <
		typename Context
	> void
	GenericFSM<Context>::update (
		void
	) {
		if(m_nextState != nullptr) {
			if(m_currentState != nullptr) m_currentState->exit();
			m_currentState = m_nextState;
			m_nextState = nullptr;
			m_currentState->enter();
		}
		if(m_currentState != nullptr) m_currentState->update();
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::common::pattern