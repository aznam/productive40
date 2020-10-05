/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Logging Namespace File.
 * \details This file declares the logging namespace of the "Common" library.
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

			namespace common {

				/**
				 * \namespace lis::pecase::productive40::common::logging
				 * \brief Contains the code related to the logging namespace.
 				 * \details This namespace provides logging functionnalities to the project.
				 */
				namespace logging {

				#pragma region Class Forward Declarations

					class Logger;

					class LoggerImpl;

					class ConsoleLoggerImpl;

				#pragma endregion

				}; // namespace logging

			}; // namespace common

		}; // namespace productive40

	}; // namespace pecase

}; // namespace lis

/*
===================================================================================================
	Namespace Includes
===================================================================================================
*/
#include "logging/logger.hpp"
#include "logging/logger_impl.hpp"
#include "logging/console_logger_impl.hpp"