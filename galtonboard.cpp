#include "galtonboard.h"
#include <QTimer>
#include <QRect>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

GaltonBoard::GaltonBoard(QWidget *parent)
    : QWidget (parent)
{
//    startTimer(200);
}

void GaltonBoard::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.fillRect(rect(), Qt::red);

    for (const auto &r : m_pins) p.drawRect(r);

    qDebug() << "redraw";
}

void GaltonBoard::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Left click.";
    } else {
        qDebug() << "Right click.";
    }

    m_pins.push_back({0, 0, 100, 100});

    update();
}

//void GaltonBoard::timerEvent(QTimerEvent *)
//{
//    pins.back().setX(pins.back().x() + 1);
//    pins.back().setY(pins.back().y() + 1);
//    update();
//}
