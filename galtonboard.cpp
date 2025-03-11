#include "galtonboard.h"
#include <QTimer>
#include <QRect>
#include <QPainter>
#include <QDebug>

GaltonBoard::GaltonBoard(QWidget *parent) :
    QWidget (parent)
{
    startTimer(200);
    pins.append(QRect(QPoint(0, 0), QPoint(0, 0)));
}

void GaltonBoard::timerEvent(QTimerEvent *)
{
    pins.back().setX(pins.back().x() + 1);
    pins.back().setY(pins.back().y() + 1);
    update();
}

void GaltonBoard::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(10);
    p.drawRects(pins);
}
