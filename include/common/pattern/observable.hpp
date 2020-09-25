#pragma once

#include <set>

namespace lis::pecase::productive40::common::pattern {

#pragma region Types Definitions

	template <
		typename ObserverInterface
	> class Observable {

	#pragma region Instance Data Members

		protected:
		std::set<ObserverInterface *>
		m_observers;

	#pragma endregion

	#pragma region Constructors / Destructor

		#pragma region Constructors

		protected:
		Observable (
			void
		);

		#pragma endregion

		#pragma region Destructor

		protected: virtual
		~Observable (
			void
		) = 0;

		#pragma endregion

	#pragma endregion

	#pragma region Observer Handling

		#pragma region Instance Methods

		public: void
		subscribe (
			ObserverInterface *
		);

		public: void
		unsubscribe (
			ObserverInterface *
		);

		public:
		template <
			typename... Params
		> void
		notify(
			void (ObserverInterface::*) (const Observable<ObserverInterface> &, Params...),
			Params...
		);

		#pragma endregion

	#pragma endregion

	};

#pragma endregion

}; // namespace lis::pecase::productive40::common::pattern

#include "observable.tpp"