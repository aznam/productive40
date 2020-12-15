/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides an implementation of the robot widget.
 * \details This file implements the main window of the robot widget.
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
#include "../../../../include/missionplanner/ui/widget/robot_widget.hpp"

/*
===================================================================================================
	Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::widget {

#pragma region Static Variables Initializations

	const char*
	RobotWidget::Robot_Pixmap_Filename_ = ":/MainWindow/pictures/robot.png";

	const qreal
	RobotWidget::Robot_Pixmap_Origin_X_  = 16;

	const qreal
	RobotWidget::Robot_Pixmap_Origin_Y_  = 16;

#pragma endregion

#pragma region Constructors / Destructor

	RobotWidget::RobotWidget (
		const robot::RobotModel & robot_model
	) :
		QGraphicsPixmapItem(QPixmap(RobotWidget::Robot_Pixmap_Filename_)),
		m_robotModel((robot::RobotModel &) robot_model) {
		this->setTransformOriginPoint(
			RobotWidget::Robot_Pixmap_Origin_X_,
			RobotWidget::Robot_Pixmap_Origin_Y_
		);
		this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable, true);
		this->setPos(robot_model._x, robot_model._y);
		QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect();
		this->setGraphicsEffect(effect);
		effect->setColor(QColor::fromRgb(255,0,0));
		this->setSelected(false);
	}

	RobotWidget::~RobotWidget (
		void
	) {
		delete this->graphicsEffect();
	}

#pragma endregion

#pragma region Methods Definitions and Implementations

	#pragma region Effects Handling

	void
	RobotWidget::setSelected (
		bool selected
	) {
		this->QGraphicsItem::setSelected(selected);
		this->graphicsEffect()->setEnabled(selected);
	}

	#pragma endregion

	#pragma region Robot Model Accesors (Getters)

	const robot::RobotModel &
	RobotWidget::robotModel (
		void
	) {
		return this->m_robotModel;
	}

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::widget