#include "ball.h"

Ball::Ball(QPointF position, QSizeF size, QRectF boundingBox, wtm::Vec2T<float> velocity):
        DynamicGraphicalPrimitive(position, size, boundingBox, velocity) {}

void Ball::draw() {}



