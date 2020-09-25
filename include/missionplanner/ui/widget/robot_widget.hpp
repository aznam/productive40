#pragma once

#include <QGraphicsPixmapItem>

#include "../../robot/robot_interface.hpp"

namespace lis::pecase::productive40::missionplanner::ui::widget {

	class RobotWidget :
		public QGraphicsPixmapItem,
		public robot::RobotInterface {

		private:
		QString
		m_name;

		public:
		RobotWidget (
			const std::string &
		);

		public:
		~RobotWidget (
			void
		);

		public:
		void
		toggleSelect (
			void
		);

		public:
		void
		select (
			bool
		);

		public:
		void
		move (
			double,
			double
		) override;

		public:
		QString
		name (
			void
		) const;

	};

}