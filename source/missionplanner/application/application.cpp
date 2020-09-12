/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the application.
 * \details This file implements the main application.
 */

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../include/missionplanner/application/application.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application {

#pragma region Constructors / Destructor

	Application::Application (
		int argc,
		char ** argv
	) :
		QApplication(argc, argv) {
		this->m_mainWindow.show();
	}

	Application::~Application (
		void
	) {
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application