#include "ball.h"
#include "constants.h"

using namespace global;

Ball::Ball(const Vec2 &position, const Vec2 &velocity, const double radius)
   : DynamicGraphicalPrimitive (position, velocity), m_radius(radius) {}

void Ball::draw(QPainter &p) const
{
    p.drawEllipse(QPointF(position().x(), position().y()), radius(), radius());
}

QRectF Ball::boundingBox() const
{
    return QRectF(position().x() - radius(), position().y() - radius(), radius() * 2, radius() * 2);
}
