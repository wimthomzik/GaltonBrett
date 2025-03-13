#include "ball.h"

Ball::Ball(Vec2 position, QRectF boundingBox, Vec2 velocity)
    : DynamicGraphicalPrimitive (position, boundingBox, velocity) {}

void Ball::draw(QPainter &p) const
{
    p.drawRect(boundingBox());
    p.drawEllipse(boundingBox());
}
