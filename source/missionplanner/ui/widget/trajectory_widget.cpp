/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the trajectory widget.
 * \details This file implements the main window of the trajectory widget.
 */

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QGraphicsColorizeEffect>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/ui/widget/trajectory_widget.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::widget {

#pragma region Static Variables Initializations

	const uint32
	TrajectoryWidget::Trajectory_Point_Radius_ = 5;

#pragma endregion

#pragma region Constructors / Destructor

	std::vector<Eigen::Vector2d>
	TrajectoryWidget::toVector() {
		std::vector<Eigen::Vector2d> points;
		for(auto w : this->childItems()) {
			TrajectoryWidget::PointWidget* wp =
				(TrajectoryWidget::PointWidget*)w;
			points.push_back(Eigen::Vector2d(wp->_x, wp->_y));
		}

		return points;
	}

	TrajectoryWidget::PointWidget::PointWidget (
		TrajectoryWidget * parent,
		qreal x,
		qreal y
	) :
		QGraphicsEllipseItem(
			x,
			y,
			TrajectoryWidget::Trajectory_Point_Radius_,
			TrajectoryWidget::Trajectory_Point_Radius_,
			parent
		) {
		this->_x = x;
		this->_y = y;
		this->setParentItem(parent);
		this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsMovable, false);
		this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsFocusable, false);
		this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable, true);
		//this->setPos(this->mapFromScene(x, y));
		QGraphicsColorizeEffect * effect = new QGraphicsColorizeEffect();
		this->setGraphicsEffect(effect);
		effect->setColor(QColor::fromRgb(255, 0, 0));
	}
	
	TrajectoryWidget::TrajectoryWidget (
		const robot::RobotModel & robot_model
	) :
		QGraphicsItem(),
		m_robotModel((robot::RobotModel &) robot_model) {
		this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsMovable, false);
		this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsFocusable, false);
		this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable, false);
	}

	TrajectoryWidget::PointWidget::~PointWidget (
		void
	) {
		delete this->graphicsEffect();
	}

	TrajectoryWidget::~TrajectoryWidget (
		void
	) {
		this->clear();
	}

#pragma endregion

#pragma region Methods Definitions and Implementations

	#pragma region Trajectory Management

	void
	TrajectoryWidget::addPoint (
		qreal x,
		qreal y
	) {
		PointWidget* point = new PointWidget(this, x, y);
	}

	void
	TrajectoryWidget::clear (
		void
	) {
		for(auto w : this->childItems()) {
			w->setParentItem(nullptr);
			delete w;
		}
	}

	void
	TrajectoryWidget::toggleSelectable (
		bool toggle
	) {
		for(auto w : this->childItems()) {
			w->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable, toggle);
		}
	}

	#pragma endregion

	#pragma region Draw Methods

	QRectF
	TrajectoryWidget::boundingRect (
		void
	) const {
		return this->childrenBoundingRect();
	}

	void
	TrajectoryWidget::paint (
		QPainter * painter,
		const QStyleOptionGraphicsItem * option,
		QWidget * widget
	) {
		// for(auto w : this->childItems()) w->paint(painter, option, widget);
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::widget