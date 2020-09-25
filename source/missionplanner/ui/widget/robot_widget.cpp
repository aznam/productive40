#include <QGraphicsColorizeEffect>
#include "../../../../include/missionplanner/ui/widget/robot_widget.hpp"

namespace lis::pecase::productive40::missionplanner::ui::widget {

	RobotWidget::RobotWidget (
		const std::string & name
	) :
		QGraphicsPixmapItem(QPixmap(":/MainWindow/pictures/robot.png")),
		m_name(QString::fromStdString(name)) {
		this->setTransformOriginPoint(16, 16);
		this->setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsFocusable, true);
		this->setGraphicsEffect(new QGraphicsColorizeEffect());
		((QGraphicsColorizeEffect *)this->graphicsEffect())->setColor(QColor::fromRgb(255,0,0));
		this->select(false);
	}

	RobotWidget::~RobotWidget (
		void
	) {
	}

	void
	RobotWidget::toggleSelect (
		void
	) {
		this->graphicsEffect()->setEnabled(!this->graphicsEffect()->isEnabled());
	}

	void
	RobotWidget::select (
		bool selected
	) {
		this->graphicsEffect()->setEnabled(selected);
	}

	void
	RobotWidget::move (
		double x,
		double y
	) {
		this->moveBy(x, y);
	}

	QString
	RobotWidget::name (
		void
	) const {
		return this->m_name;
	}

};