/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Communication types header.
 * \details This file contains the definitions of types used in communication namespace.
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

			namespace robotapi {

				namespace communication {

					/**
					 * \namespace lis::pecase::productive40::robotapi::communication::types
					 * \brief Contains the definitions of types used in communication namespace.
					 * \details Contains the definitions of types used in communication namespace.
					 */
					namespace types {

					#pragma region Types Definitions

						/**
						 * \enum MessageCode
						 * \brief Discovery Message Code.
						 * \details Discovery Message Code.
						 */
						enum MessageCode {

							/**
							 * \brief Discovery Code.
							 * \details Discovery Code.
							 */
							Discovery = 0x01,

							/**
							 * \brief Welcome Code.
							 * \details Welcome Code.
							 */
							Welcome = 0x02,

							/**
							 * \brief Informations Code.
							 * \details Informations Code.
							 */
							Informations = 0x03,

						};

					#pragma endregion

					}; // namespace types

				#pragma region Types Definitions

					/**
					 * \typedef lis::pecase::productive40::robotapi::communication::MessageCode
					 * \brief Alias for types::MessageCode.
					 * \details Alias for types::MessageCode.
					 */
					typedef types::MessageCode MessageCode;

				#pragma endregion

				}; // namespace communication

			}; // namespace robotapi
			
		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis