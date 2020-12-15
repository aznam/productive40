/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Robot Widget.
 * \details This file provides the interface of the Robot Widget.
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
#include <QtWidgets/QGraphicsPixmapItem>

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
	 * \class RobotWidget include/missionplanner/ui/widget/robot_widget.hpp \
	 * <productive40/missionplanner/ui/widget/robot_widget.hpp>
	 * \brief Robot Widget.
	 * \details This class implements a robot widget for mission planning.
	 * \nosubgrouping
	 */
	class RobotWidget :
		public QGraphicsPixmapItem {

	/**
	 * \name Constants
	 */
	#pragma region Class Constants
	/**@{*/

		/**
		 * \brief Robot pixmap filename.
		 * \details Robot pixmap filename.
		 */
		private: static
		const char*
		Robot_Pixmap_Filename_;

		/**
		 * \brief X-coordinate of pixmap origin.
		 * \details X-coordinate of pixmap origin.
		 */
		private: static
		const qreal
		Robot_Pixmap_Origin_X_;

		/**
		 * \brief Y-coordinate of pixmap origin.
		 * \details Y-coordinate of pixmap origin.
		 */
		private: static
		const qreal
		Robot_Pixmap_Origin_Y_;

	/**@}*/
	#pragma endregion

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
		RobotWidget (
			const robot::RobotModel &
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~RobotWidget (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	#pragma region Effects Handling
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Select the robot.
		 * \details Select the robot.
		 * \param[in] selected Flag indicating if the robot is selected.
		 */
		public:
		void
		setSelected (
			bool
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

	}; // class RobotWidget

#pragma endregion

} // namespace lis::pecase::productive40::missionplanner::ui::widget