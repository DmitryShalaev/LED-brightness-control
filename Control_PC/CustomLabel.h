#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>

class CustomLabel final : public QLabel {
	Q_OBJECT

	public:

	explicit CustomLabel(QWidget* parent = nullptr);

	void mousePressEvent(QMouseEvent* event) override;

	signals:
	void Clicked();
};


#endif // CUSTOMLABEL_H
