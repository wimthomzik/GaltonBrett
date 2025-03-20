#include "floor.h"

Floor::Floor(const Vec2 &position)
    : StaticGraphicalPrimitive(position) {}

void Floor::draw(QPainter &p) const
{
    p.drawLine(position().x() + 100, position().y(), position().x() + 300, position().y());
}

QRectF Floor::boundingBox() const
{
    return QRectF(position().x(), position().y(), 200, -10);
}
