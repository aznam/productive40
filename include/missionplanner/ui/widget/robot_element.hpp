/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Robot Element (QListWidget).
 * \details This file provides the interface of the Robot Element (QListWidget).
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
#include <QtWidgets/QListWidgetItem>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../robot.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::widget {

#pragma region Types Definitions

	/**
	 * \class RobotElement include/missionplanner/ui/widget/robot_element.hpp \
	 * <productive40/missionplanner/ui/widget/robot_element.hpp>
	 * \brief Robot Element.
	 * \details This class implements a robot list item for mission planning.
	 * \nosubgrouping
	 */
	class RobotElement :
		public QListWidgetItem {

	/**
	 * \name Instance Data Members
	 */
	#pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Reference to the robot model.
		 * \details Reference to the robot model.
		 */
		private:
		const robot::RobotModel &
		m_robotModel;

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
		 * \param[in] robot_model (const robot::RobotModel &) Reference to a robot model.
		 */
		public:
		RobotElement (
			const robot::RobotModel &
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~RobotElement (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot Model Accesors (Getters)
	 */
	#pragma region Robot Model Accesors (Getters)
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Return a reference to the robot model.
		 * \details Return a reference to the robot model.
		 * \return (const robot::RobotModel &) Reference to the robot model.
		 */
		public:
		const robot::RobotModel &
		robotModel(
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class RobotElement

#pragma endregion

} // namespace lis::pecase::productive40::missionplanner::ui::widget