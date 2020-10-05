/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Observable Interface.
 * \details This file provides an interface for observable objects.
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
#include <set>

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::pattern {

#pragma region Types Definitions

	/**
	 * \class Observable include/common/pattern/observable.hpp \
	 * <productive40/common/pattern/observable.hpp>
	 * \brief Generic Implementation of Observable.
	 * \details This template class turns any class into an Observable Type.
	 *
	 * Example of real implementation:
	 * \snippet example/observable.hpp Observable Implementation
	 * \tparam ObservableInterface Interface of the observers for this observable object.
	 * \nosubgrouping
	 */
	template <
		typename ObserverInterface
	> class Observable {

	/**
	 * \name Instace Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief References to the observers.
		 * \details List of observers observing this observable.
		 */
		protected:
		std::set<ObserverInterface *>
		m_observers;

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
		 * \default Default constructor.
		 */
		protected:
		Observable (
			void
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		protected: virtual
		~Observable (
			void
		) = 0;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Observer Handling
	 */
	#pragma region Observer Handling
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Subscribe an observer.
		 * \details This method allows an observer to subscribe to this observable.
		 * \param observer (ObserverInterface *) Pointer to an observer.
		 */
		public: void
		subscribe (
			ObserverInterface *
		);

		/**
		 * \brief Unsubscribe an observer.
		 * \details This method allows an observer not to observe this observable anymore.
		 * \param observer (ObserverInterface *) Pointer to an observer.
		 */
		public: void
		unsubscribe (
			ObserverInterface *
		);

		/**
		 * \brief Notify the observer of an event.
		 * \details This method notifies the subscribed observers of an event.
		 * \tparam Params List of parameters of the notified method.
		 * \param func \
		 * void (ObserverInterface::*) (const Observable<ObserverInterface> &, Params...) \
		 * Pointer to the method of the interface to call.
		 * \param params (Params...) List of parameters.
		 */
		protected:
		template <
			typename... Params
		> void
		notify (
			void (ObserverInterface::*) (const Observable<ObserverInterface> &, Params...),
			Params...
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class Observer<ObservableInterface>

#pragma endregion

}; // namespace lis::pecase::productive40::common::pattern

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "observable.tpp"