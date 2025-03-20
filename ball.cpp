#include "ball.h"


Ball::Ball(const Vec2 &position, const Vec2 &velocity, const double radius)
    : DynamicGraphicalPrimitive (position, velocity), m_radius(radius) {}

void Ball::draw(QPainter &p) const
{
    p.translate(100 - radius() / 2, 10);
    p.drawEllipse(position().x(), position().y(), radius() / 2, radius() / 2);
    p.translate(-100 + radius() / 2, -10);
}

QRectF Ball::boundingBox() const
{
    return QRectF(position().x(), position().y(), radius() / 2, radius() / 2);
}
