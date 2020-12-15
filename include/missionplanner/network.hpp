/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Network Namespace File.
 * \details This file declares the Network namespace of the mission planner.
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

				/**
				 * \namespace lis::pecase::productive40::missionplanner::network
				 * \brief Contains the code related to network handling in the mission planner.
				 * \details Contains the code related to network handling in the mission planner.
				 */
				namespace network {

				#pragma region Forward Declarations

					class NetworkManager;

					class NetworkManagerImpl;

				#pragma endregion

				}; //namespace network

			}; // namespace missionplanner

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "network/network_manager.hpp"
#include "network/network_manager_impl.hpp"
#include "network/delegate.hpp"