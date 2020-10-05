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
	Python Includes
===================================================================================================
*/
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/eigen.h>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../../../include/common/math/functions.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::common::math::functions {
	
#pragma region Functions Definitions & Implementations

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

	#pragma region Control System

	Eigen::MatrixXd
	place_poles (
		const Eigen::MatrixXd & A,
		const Eigen::MatrixXd & B,
		const Eigen::VectorXd & poles
	) {
		pybind11::scoped_interpreter guard;
		pybind11::module scipy_signal = pybind11::module::import("scipy.signal");

		pybind11::object result = scipy_signal.attr("place_poles")(A, B, poles, "KNV0");

		return pybind11::cast<Eigen::MatrixXd>(result.attr("gain_matrix"));
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::common::math::functions