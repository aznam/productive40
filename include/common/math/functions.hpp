/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file declares math helpers.
 * \details This file declares common math operations.
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

				namespace math {

					/**
					 * \namespace lis::pecase::productive40::common::math::functions
					 * \brief This namespace contains definitions of math operations.
					 * \details This namespace contains definitions of mathematical operations.
					 */
					namespace functions {

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

						#pragma region Control System

						/**
						 * \brief Computes K such that eigenvalues (A - dot(B, K))=poles.
						 * \details Compute K such that eigenvalues (A - dot(B, K))=poles. This
						 * function use scipy implementation of place_poles.
						 * \param[in] A (const Eigen::MatrixXd &) Matrix A.
						 * \param[in] B (const Eigen::MatrixXd &) Matrix B.
						 * \param[in] poles (const Eigen::MatrixXd &) Poles.
						 * \return (Eigen::MatrixXd) The K Matrix.
						 */
						Eigen::MatrixXd
						place_poles (
							const Eigen::MatrixXd &,
							const Eigen::MatrixXd &,
							const Eigen::VectorXd &
						);

						#pragma endregion

					#pragma endregion

					}; // namespace functions

				#pragma region Functions Aliases

					/**
					 * \brief Function alias for euclidian_distance.
					 * \details Function alias for euclidian_distance.
					 */
					static
					double (* const euclidian_distance_2)(
						const Eigen::Vector2d &,
						const Eigen::Vector2d &
					) = functions::euclidian_distance;

					/**
					 * \brief Function alias for euclidian_distance.
					 * \details Function alias for euclidian_distance.
					 */
					static
					double (* const euclidian_distance_3)(
						const Eigen::Vector3d &,
						const Eigen::Vector3d &
					) = functions::euclidian_distance;

					/**
					 * \brief Function alias for place_poles.
					 * \details Function alias for place_poles.
					 */
					static
					Eigen::MatrixXd (* const place_poles)(
						const Eigen::MatrixXd &,
						const Eigen::MatrixXd &,
						const Eigen::VectorXd &
					) = functions::place_poles;

				#pragma endregion

				}; // namespace math

			}; // namespace common

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis