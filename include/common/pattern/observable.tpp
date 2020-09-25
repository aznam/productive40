#pragma once

#include "observable.hpp"

namespace lis::pecase::productive40::common::pattern {

#pragma region Constructors / Destructor

	template <
		typename ObserverInterface
	> Observable<ObserverInterface>::Observable (
			void
	) {
	}

	template <
		typename ObserverInterface
	> Observable<ObserverInterface>::~Observable (
		void
	) {
		m_observers.clear();
	}

#pragma endregion

#pragma region Observer Handling


	template <
		typename ObserverInterface
	> void
	Observable<ObserverInterface>::subscribe (
		ObserverInterface * observer
	) {
		if(observer == nullptr) return;
		m_observers.insert(observer);
	}

	template <
		typename ObserverInterface
	> void
	Observable<ObserverInterface>::unsubscribe (
		ObserverInterface * observer
	) {
		if(observer == nullptr) return;
		m_observers.erase(observer);
	}

	template <
		typename ObserverInterface
	>
	template <
		typename... Params
	> void
	Observable<ObserverInterface>::notify(
		void (ObserverInterface::*func) (const Observable<ObserverInterface> &, Params...),
		Params... params
	) {
		for(auto iter = m_observers.begin(); iter != m_observers.end(); iter++) {
			((*iter)->*func)(*this, params...);
		}
	}
	
#pragma endregion

}; // namespace lis::pecase::productive40::common::pattern

#include "observable.tpp"