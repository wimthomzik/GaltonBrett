#include "ball.h"

Ball::Ball(const Vec2 &position, const QRectF &boundingBox, const Vec2 &velocity)
    : DynamicGraphicalPrimitive (position, boundingBox, velocity) {}

void Ball::draw(QPainter &p) const
{
    p.save();
    p.translate(position().x(), position().y());
    p.drawRect(boundingBox());
    p.drawEllipse(boundingBox());
    p.restore();
}
