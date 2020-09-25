/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Math Namespace File.
 * \details This file declares the math namespace of the "Common" library.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Eigen Includes
===================================================================================================
*/
#include <Eigen/Dense>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis {
	
	namespace pecase {

		namespace productive40 {

			namespace common {

				/**
				 * \namespace lis::pecase::productive40::common::math
				 * \brief Contains the code related to the math namespace.
 				 * \details This namespace complements Eigen and provides useful routines
				 * and operations.
				 */
				namespace math {

				#pragma region Functions Forward Declarations

					#pragma region Distance Computation

					/**
					 * \brief Compute the euclidian distance between two points.
					 * \details Compute the euclidian distance between two points.
					 * \param[in] p1 (const Eigen::Vector2d &) Point 1.
					 * \param[in] p2 (const Eigen::Vector2d &) Point 2.
					 * \return (double) Distance between P1 and P2.
					 */
					double
					euclidian_distance (
						const Eigen::Vector2d &,
						const Eigen::Vector2d &
					);

					/**
					 * \brief Compute the euclidian distance between two points.
					 * \details Compute the euclidian distance between two points.
					 * \param[in] p1 (const Eigen::Vector3d &) Point 1.
					 * \param[in] p2 (const Eigen::Vector3d &) Point 2.
					 * \return (double) Distance between P1 and P2.
					 */
					double
					euclidian_distance (
						const Eigen::Vector3d &,
						const Eigen::Vector3d &
					);

					#pragma endregion

				#pragma endregion

				}; // namespace math

			}; // namespace common

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis