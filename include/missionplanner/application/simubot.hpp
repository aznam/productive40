/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of a simulated robot in the mission planner.
 * \details This file provides the interface of a simulated robot in the mission planner.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Standard Include
===================================================================================================
*/
#include <memory>

/*
===================================================================================================
    Qt Include
===================================================================================================
*/
#include <QThread>
#include <QTimer>

/*
===================================================================================================
    Project Includes
===================================================================================================
*/
#include "robot/simubot_interface.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application {

#pragma region Types Definitions

	/**
	 * \class Simubot include/missionplanner/application/simubot.hpp \
	 * <productive40/missionplanner/application/simubot.hpp>
	 * \brief Simubot Main Class.
	 * \details This class implements a simulated robot inside the mission planner, in order to
	 * test algorithm without needing the implementation of ROS. Each robot is thus represented
	 * by a thred which run independently of the main application.
	 * \nosubgrouping
	 */
    class Simubot :
		public QThread {

        Q_OBJECT

	/**
	 * \name Constants
	 */
	#pragma region Constants
	/**@{*/

		/**
		 * \brief Simubot Update Frequency.
		 * \details This constant simulates the CPU frequency of a simulated robot (in ms).
		 */
		private: const
		unsigned long
		m_CPUfrequency = 300;


	/**@}*/
	#pragma endregion

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Identifier of the robot.
		 * \details Identifier of the robot.
		 */
		private:
		unsigned int
		m_identifier;

		/**
		 * \brief Interface to interact the robot.
		 * \details Interface to interact with the robot.
		 */
        private:
        robot::SimubotInterface
        m_robotInterface;

		/**
		 * \brief Robot Update Frequency.
		 * \details This timer refresh the state of the robot.
		 */
		private:
		QTimer
		m_refreshTimer;

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
		 * \param[in] parent (QObject *) Parent of the thread.
		 * \param[in] identifier (unsigned int) Id of the robot.
		 */
        public:
        Simubot (
            QObject *,
			unsigned int
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        public:
        ~Simubot (
            void
        );

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Thread Operations
	 */
	#pragma region Thread Operations
	/**@{*/

		#pragma region Overriden Methods

		/**
		 * \brief Entry point of the thread.
		 * \details The starting point for the thread. After calling start(), the newly created
		 * thread calls this function. The default implementation simply calls exec().
		 *
		 * You can reimplement this function to facilitate advanced thread management. Returning
		 * from this method will end the execution of the thread.
		 */
		protected:
		void
		run (
			void
		) override;

		#pragma endregion

		#pragma region Slots

		/**
		 * \brief Robot refresh.
		 * \details Refresh the robot state.
		 */
		private slots:
		void
		refresh (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class Simubot

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application