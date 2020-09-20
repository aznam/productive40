/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Delegate Namespace File.
 * \details This file declares the network::delegate namespace of the mission planner.
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
namespace lis {
	
	namespace pecase {

		namespace productive40 {

			namespace missionplanner {

				namespace network {

					/**
					 * \namespace lis::pecase::productive40::missionplanner::network::delegate
					 * \brief Contains the code related to the realization of network components.
					 * \details Contains the code related to the realization of network components.
					 */
					namespace delegate {

					#pragma region Forward Declarations

						class FakeCommunicationImpl;

						class RosCommunicationImpl;

						class InetCommunicationImpl;

					#pragma endregion

					}; // namespace delegate

				}; //namespace network

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "delegate/fake_communication_impl.hpp"
//#include "delegate/ros_communication_impl.hpp"
//#include "delegate/inet_communication_impl.hpp"

/*
===================================================================================================
    Macros
===================================================================================================
*/