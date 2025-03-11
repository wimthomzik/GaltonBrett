#include "canvas.h"
#include "galtonboard.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;


Canvas::Canvas(QWidget *parent)
    : QWidget(parent)/*, m_galtonBoard(new GaltonBoard(this))*/ {}


void Canvas::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.translate(m_offset.x(), m_offset.y());
    p.scale(m_scale.x(), -m_scale.y());
    p.drawEllipse(200, 200, 300, 300);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    m_prevPos.setXY(event->x(), event->y());
}


void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    m_offset += Vec2(event->x(), event->y()) - m_prevPos;
    m_prevPos.setXY(event->x(), event->y());
    update();
}

void Canvas::wheelEvent(QWheelEvent *event)
{
    Vec2 mousePos;
    mousePos.setXY(event->pos().x(), event->pos().y());

    double scaleFactor = (event->delta() > 0) ? 1.1 : 0.9;

    m_offset = (mousePos - (mousePos - m_offset) * scaleFactor);

    m_scale *= scaleFactor;

    update();
}


