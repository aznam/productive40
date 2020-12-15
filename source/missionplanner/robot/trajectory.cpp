/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the trajectory model.
 * \details This file implements the trajectory model.
 */

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../include/missionplanner/robot/trajectory.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::robot {

#pragma region Constructors / Destructor

	Trajectory::Trajectory (
		void
	) :
		m_points() {
	}

	Trajectory::Trajectory (
		const Trajectory & trajectory
	) :
		m_points(trajectory.m_points) {
	}

	Trajectory::~Trajectory (
		void
	) {
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::robot