/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the model of a trajectory.
 * \details This file provides the model of a trajectory.
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
#include <string>
#include <list>

/*
===================================================================================================
	Eigen Includes
===================================================================================================
*/
#include <Eigen/Dense>

/*
===================================================================================================
	Framework Includes
===================================================================================================
*/
#include <types.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::robot {
     
#pragma region Types Definitions

	/**
	 * \class Trajectory include/missionplanner/robot/trajectory.hpp \
	 * <productive40/missionplanner/robot/trajectory.hpp>
	 * \brief Trajectory Model.
	 * \details This class represents a trajectory and holds data concernig a trajectory.
	 * \nosubgrouping
	 */
    class Trajectory {

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief List of points which compose the trajectory.
		 * \details List of points which composes the trajectory.
		 */
		private:
		std::list<Eigen::Vector2d>
		m_points;

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
		public:
		Trajectory (
			void
		);

		/**
		 * \brief Copy ctor.
		 * \details Copy constructor.
		 * \param[in] trajectory (const Trajectory &) Trajectory to be copied.
		 */
		public:
		Trajectory (
			const Trajectory &
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~Trajectory (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class Trajectory

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::robot