/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Trajectory Widget.
 * \details This file provides the interface of the Trajectory Widget.
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
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsLineItem>
#include <QtWidgets/QGraphicsEllipseItem>

/*
===================================================================================================
	Framework Includes
===================================================================================================
*/
#include <types.hpp>

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
	 * \class TrajectoryWidget include/missionplanner/ui/widget/trajectory_widget.hpp \
	 * <productive40/missionplanner/ui/widget/trajectory_widget.hpp>
	 * \brief Trajectory Widget.
	 * \details This class implements a trajectory widget for mission planning.
	 * \nosubgrouping
	 */
	class TrajectoryWidget :
		public QGraphicsItem {

	#pragma region Nested Types Definitions

		/**
		 * \class PointWidget include/missionplanner/ui/widget/trajectory_widget.hpp \
		 * <productive40/missionplanner/ui/widget/trajectory_widget.hpp>
		 * \brief Trajectory Point Widget.
		 * \details This class implements a trajectory point widget for mission planning.
		 * \nosubgrouping
		 */
		private:
		class PointWidget :
			public QGraphicsEllipseItem {

			public: double _x; public: double _y;

		/**
		 * \name Constructors / Destructor
		 */
		#pragma region Constructors / Destructor
		/**@{*/

			#pragma region Constructors

			/**
			 * \brief Default ctor.
			 * \details Default constructor.
			 * \param[in] parent (TrajectoryWidget *) Parent trajectory.
			 * \param[in] x (qreal) X-coordinate.
			 * \param[in] y (qreal) Y-coordinate.
			 */
			public:
			PointWidget (
				TrajectoryWidget *,
				qreal,
				qreal
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brief Default dtor.
			 * \details Default destructor.
			 */
			public:
			~PointWidget (
				void
			);

			#pragma endregion

		/**@}*/
		#pragma endregion

		};
		

	#pragma endregion

	/**
	 * \name Constants
	 */
	#pragma region Class Constants
	/**@{*/

		/**
		 * \brief Radius of trajectory point.
		 * \details Radius of trajectory point.
		 */
		private: static
		const uint32
		Trajectory_Point_Radius_;

		/**
		 * \brief Line pen.
		 * \details Line pen
		 */
		/*private: static
		const QPen
		Trajectory_Line_Pen_;*/

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
		TrajectoryWidget (
			const robot::RobotModel &
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~TrajectoryWidget (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	#pragma region Trajectory Management
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Add a point.
		 * \detais Add a point.
		 * \param[in] x (qreal) X-coordinate of the point.
		 * \param[in] y (qreal) Y-coordinate of the point.
		 */
		public:
		void
		addPoint (
			qreal,
			qreal
		);

		/**
		 * \brief Clear the trajectory.
		 * \details Clear the trajectory.
		 */
		public:
		void
		clear (
			void
		);

		/**
		 * \brief Toggle selection capability.
		 * \details Togge selection capability.
		 * \param[in] toggle (bool) Flag.
		 */
		public:
		void
		toggleSelectable (
			bool
		);

		public:
		std::vector<Eigen::Vector2d>
		toVector();

		#pragma endregion

	/**@}*/
	#pragma endregion

	#pragma region Draw Methods
	/**@{*/

		#pragma region Implemented Methods

		/**
		 * \brief Returns the bounding rect.
		 * \details Returns the bounding rect.
		 * \returns (QRectF) The bounding rect.
		 */
		public:
		QRectF
		boundingRect (
			void
		) const override;

		/**
		 * \brief Draw the widget.
		 * \details Draw the widget.
		 */
		public:
		void
		paint (
			QPainter *,
			const QStyleOptionGraphicsItem *,
			QWidget *
		) override;

		#pragma endregion

	/**@}*/
	#pragma endregion

	}; // class TrajectoryWidget

#pragma endregion

} // namespace lis::pecase::productive40::missionplanner::ui::widget