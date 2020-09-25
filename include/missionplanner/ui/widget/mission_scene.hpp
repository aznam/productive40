#pragma once

#include <QGraphicsScene>
#include <QString>

#include "robot_widget.hpp"

namespace lis::pecase::productive40::missionplanner::ui::widget {

	class MissionScene :
		public QGraphicsScene {

		Q_OBJECT

		private:
		std::map<QString, RobotWidget *>
		m_robotWidgets;

		private:
		std::vector<QGraphicsEllipseItem *>
		m_trajectoryPointItem;

		public:
		MissionScene (
			qreal,
			qreal,
			qreal,
			qreal,
			QObject * = nullptr
		);

		public:
		~MissionScene (
			void
		);

		public:
		QGraphicsEllipseItem *
		createTrajectoryPoint (
			double,
			double
		);

		public:
		RobotWidget *
		createRobotWidget (
			const std::string &
		);

		public:
		RobotWidget *
		findRobotWidget (
			const QString &
		) const;

		public:
		void
		unselectAll (
			void
		);

		public:
		void
		select (
			const QList<QString> &
		);

		public:
		void
		select (
			RobotWidget *
		);

		protected:
		void
		mousePressEvent(
			QGraphicsSceneMouseEvent *
		) override;

		/**
		 * \brief
		 * \details
		 */
		protected:
		void
		mouseReleaseEvent(
			QGraphicsSceneMouseEvent *
		) override;

	};

}