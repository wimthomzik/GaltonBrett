#include "ball.h"


Ball::Ball(const Vec2 &position, const Vec2 &velocity, const int radius)
    : DynamicGraphicalPrimitive (position, velocity, radius) {}

void Ball::draw(QPainter &p) const
{
    p.drawEllipse(position().x(), position().y(), radius() / 2, radius() / 2);
}

QRectF Ball::boundingBox() const
{
    return QRectF(position().x() - radius(), position().y() - radius(), radius() / 2, radius() / 2);
}
