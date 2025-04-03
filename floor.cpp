#include "floor.h"

Floor::Floor(const Vec2 &position, const double width)
    : StaticGraphicalPrimitive(position), m_width(width) {}

void Floor::draw(QPainter &p) const
{
    p.drawLine(QPointF(position().x(), position().y()), QPointF(position().x() + m_width, position().y()));
}

QRectF Floor::boundingBox() const
{
    return QRectF(-m_width / 2, position().y(), m_width, -0.001);
}
