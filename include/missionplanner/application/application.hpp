/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Application Namespace File.
 * \details This file declares the Application namespace of the mission planner.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Standard Includes
===================================================================================================
*/
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

/*
===================================================================================================
    Qt Include
===================================================================================================
*/
#include <QApplication>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "../ui/main_window.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application {

#pragma region Types Definitions

	/**
	 * \class Application include/missionplanner/application/application.hpp \
	 * <productive40/missionplanner/application/application.hpp>
	 * \brief Application Main Class.
	 * \details This class represents the main Qt Application of the Mission Planner.
	 * \nosubgrouping
	 */
    class Application : public QApplication {

        Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Main Window UI.
		 * \details Main Window UI.
		 */
        private:
        ui::MainWindow
        m_mainWindow;

	/**@}*/
    #pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
    #pragma region Constructors / Destructor
	/**@{*/

        #pragma region Constructors

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 * \param[in] argc (int) Number of arguments.
		 * \param[in] argv (char **) Array of arguments.
		 */
        public:
        Application (
            int,
            char **
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        public:
        ~Application (
            void
        );

        #pragma endregion

	/**@}*/
    #pragma endregion

    }; // class Application

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application