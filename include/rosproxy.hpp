/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Robot Proxy Library Project Main Include File.
 * \details This library provides a proxy to communicate with ROS.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Projects Includes
===================================================================================================
*/
#include "rosproxy/rosproxy_defines.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis {
	
	namespace pecase {

		namespace productive40 {

			/**
			 * \namespace lis::pecase::productive40::rosproxy
			 * \brief Contains the code related to the ROSProxy.
			 * \details Contains the code related to the ROSProxy.
			 */
			namespace rosproxy {

				extern
				const char* Environment_Topic;

			}; // namespace rosproxy

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Package Includes
===================================================================================================
*/
#include "rosproxy/rosproxy_defines.hpp"
#include "rosproxy/rosmanager.hpp"