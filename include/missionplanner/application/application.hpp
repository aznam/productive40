/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Main Application of the Mission Planner.
 * \details This file provides the interface of the Main Application of the Mission Planner.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
    Qt Include
===================================================================================================
*/
#include <QApplication>
#include <QVector>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "simubot.hpp"
#include "../ui.hpp"
#include "../network.hpp"

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
    class Application :
		public QApplication {

        Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Vector of Simulated Robot.
		 * \details Number of simulated robots to run.
		 */
		private:
		QVector<Simubot *>
		m_simubots;

		/**
		 * \brief Main Window UI.
		 * \details Main Window UI.
		 */
        private:
        ui::MainWindow
        m_mainWindow;

		/**
		 * \brief Pointer to the Network Manager.
		 * \details Pointer to the Network Manager.
		 */
		private:
		network::NetworkManager &
		m_networkManager;

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

	/**
	 * \name Application Management
	 */
	#pragma region Application Management
	/**@{*/

		#pragma region Slots

		/**
		 * \brief Exit the application.
		 * \details Exit the application.
		 * \param[in] exit_code (unsigned int) Exit code.
		 */
		private slots:
		void
		exit (
			unsigned int
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Simubot Functions
	 */
	#pragma region Simubot Functions
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Create a simubot.
		 * \details Create a simubot.
		 * \param[in] robot_idx (unsigned int) Index of the robot.
		 */
		private:
		Simubot *
		createRobot (
			unsigned int
		);

		#pragma endregion
		
		#pragma region Slots

		/**
		 * \brief Thread terminated slot.
		 * \details Thread terminated slot.
		 */
		private slots:
		void
		robotTerminated (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class Application

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application