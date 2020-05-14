#include "CustomLabel.h"
#include <QMouseEvent>

CustomLabel::CustomLabel(QWidget* parent) : QLabel(parent) {}

void CustomLabel::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		QLabel::mousePressEvent(event);
		emit Clicked();
	}
}
