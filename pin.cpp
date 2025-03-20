#include "pin.h"
#include <QPainter>
#include <QPoint>
#include "constants.h"

Pin::Pin(const Vec2 &position, const double radius)
    : StaticGraphicalPrimitive(position), m_radius(radius) {}

void Pin::draw(QPainter &p) const
{
    p.translate(100 - radius() / 2, 10);
    p.drawEllipse(position().x(), position().y(), radius() / 2, radius() / 2);
    p.translate(-100 + radius() / 2, -10);
}

QRectF Pin::boundingBox() const
{
    return QRectF(position().x(), position().y(), radius() / 2, radius() / 2);
}
