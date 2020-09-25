/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief MissionPlanner Main File.
 * \details Entry point of the Mission Planner.
 */

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtWidgets/QApplication>
#include <iostream>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../include/missionplanner.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
using namespace lis::pecase::productive40;

namespace lis::pecase::productive40::missionplanner {

	common::logging::Logger console_log_;

};

#pragma region Functions Definitions

/**
 * \brief Entry point.
 * \details Entry point.
 * \param[in] argc (int) Number of arguments.
 * \param[in] argv (char * []) Array of arguments.
 * \return 0 Application finished successfully.
 * \return n An error occured.
 */
int 
main(
    int argc, 
    char * argv []
) {
	missionplanner::console_log_.addlogger(*(new common::logging::ConsoleLoggerImpl));
    missionplanner::application::Application app(argc, argv);
	return app.exec();
}

#pragma endregion