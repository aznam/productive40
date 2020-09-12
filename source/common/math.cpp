/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Math Implementation File.
 * \details This file implements the functions of the math namespace.
 */
#pragma once

/*
===================================================================================================
    Standard Includes
===================================================================================================
*/
#include <cmath>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../include/common/math.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::math {
	
#pragma region Functions Definitions

	#pragma region Distance Computation

	double
	euclidian_distance (
		const Eigen::Vector2d & p1,
		const Eigen::Vector2d & p2
	) {
		Eigen::Vector2d a = p2 - p1;
		return sqrt(a.dot(a));
	}

	double
	euclidian_distance (
		const Eigen::Vector3d & p1,
		const Eigen::Vector3d & p2
	) {
		Eigen::Vector3d a = p2 - p1;
		return sqrt(a.dot(a));
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::common::math