/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Singleton Interface.
 * \details This file provides an interface for singleton.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::pattern {

#pragma region Types Definitions

	/**
	 * \class Singleton include/common/pattern/singleton.hpp \
	 * <productive40/common/pattern/singleton.hpp>
	 * \brief Generic Implementation of Singletons.
	 * \details This template class turns any class into a Singleton.
	 * The implementation follows the Meyers Singleton Pattern.
	 * \note The Class to turn into a Singleton must have a default constructor.
	 *
	 * Example of real implementation:
	 * \snippet example/singleton.hpp Singleton Implementation
	 * \tparam Class Class to turn into a singleton.
	 * \nosubgrouping
	 */
	template <
		typename Class
	> class Singleton {

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
		Singleton (
			void
		) = default;

		/**
		 * \brief Copy ctor.
		 * \details Copy ctor (deleted).
		 */
		private:
		Singleton (
			const Singleton<Class> &
		) = delete;

		/**
		 * \brief Copy ctor.
		 * \details Copy ctor (deleted).
		 */
		private:
		Singleton (
			Singleton<Class> &&
		) = delete;

		#pragma endregion

		#pragma endregion Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		protected: virtual
		~Singleton (
			void
		) = default;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Assignment
	 */
	#pragma region Assignment
	/**@{*/

		#pragma region Operators

		/**
		 * \brief Assignment operator.
		 * \details Assignment operator (deleted).
		 */
		private:
		Singleton<Class> &
		operator= ( 
			const Singleton<Class> &
		) = delete;

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Singleton Management
	 */
	#pragma region Singleton Management
	/**@{*/

		#pragma region Static Functions

		/**
		 * \brief Return an instance of singleton.
		 * \details Returns an instance of Class (thread-safe).
		 * \returns (Class) State to add to the machine.
		 */
		public: static
		Class &
		instance (
			void
		);

		#pragma endregion
		
	/**@}*/
	#pragma endregion

	}; // class Singleton<Class>

#pragma endregion

}; // namespace lis::pecase::productive40::common::pattern

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "singleton.tpp"