/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Logger Window of the mission planner.
 * \details This file provides the interface of the Logger Window of the mission planner.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtWidgets/QDockWidget>

/*
===================================================================================================
    Generated Includes
===================================================================================================
*/
#include <ui_logger_window.hpp>

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui {
     
#pragma region Types Definitions

	/**
	 * \class LoggerWindow include/missionplanner/ui/logger_window.hpp \
	 * <productive40/missionplanner/ui/logger_window.hpp>
	 * \brief Logger Window.
	 * \details This class represents the Logger Window of the Mission Planner.
	 * \nosubgrouping
	 */
    class LoggerWindow : 
        public QDockWidget {

        Q_OBJECT

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief LoggerWindow delegate.
		 * \details Delegation to logger window internal class.
		 */
        private:
        Ui::LoggerWindowInternal
        m_internalUITemplate;

	/**@}*/
    #pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
    #pragma region Constructors / Destructor
	/**@{*/

        #pragma region Constructor

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 * \param[in] parent (QWidget *) Default parent.
		 */
        public:
        LoggerWindow (
            QWidget * = Q_NULLPTR
        );

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
        public:
        ~LoggerWindow (
            void
        );

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Logging Operations
	 */
	#pragma region Logging Operations
	/**@{*/

		#pragma region Slots

		/**
		 * \brief Log a message in the TextEdit.
		 * \details Log a message in the TextEdit.
		 * \param[in] text (const QString &) Message to log.
		 */
		public slots:
		void
		log (
			const QString &
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class LoggerWindow

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui