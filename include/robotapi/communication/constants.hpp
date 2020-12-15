/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Communication constants header.
 * \details This file declares some constants usable in the communication namespace.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Includes
===================================================================================================
*/
#include <types.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/

namespace lis {
	
	namespace pecase {

		namespace productive40 {

			namespace robotapi {

				namespace communication {

					/**
					 * \namespace lis::pecase::productive40::robotapi::communication::constants
					 * \brief Contains the definitions of constants used in the communication
					 * namespace.
					 * \details Contains the definitions of constants used in the communication
					 * namespace.
					 */
					namespace constants {

					#pragma region Constants Definitions

						/**
						 * \brief Packet size for Data Transmission.
						 * \details Packet size for Data Transmission.
						 */
						const size_t
						Packet_Size = 128;

					#pragma endregion

					}; // namespace constants

				#pragma region Constants Definitions

					/**
					 * \brief Alias for packet size.
					 * \details Alias for packet size.
					 */
					static
					const size_t &
					Packet_Size = constants::Packet_Size;

				#pragma endregion

				}; //namespace communication

			}; // namespace robotapi
			
		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis