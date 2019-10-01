#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>

class CustomLabel : public QLabel
{
    Q_OBJECT

public:

    explicit CustomLabel(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent* event);

signals:
    void Clicked();

public slots:
};


#endif // CUSTOMLABEL_H
