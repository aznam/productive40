/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Robot Proxy Library Project Main Include File.
 * \details 
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
			 * \brief
 			 * \details
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
	Projects Includes
===================================================================================================
*/
#include "rosproxy/rosproxy_defines.hpp"
#include "rosproxy/rosmanager.hpp"