#include "pin.h"
#include <QPainter>
#include <QPointF>
#include "constants.h"

using namespace global;

Pin::Pin(const Vec2 &position, const double radius)
    : StaticGraphicalPrimitive(position), m_radius(radius) {}

void Pin::draw(QPainter &p) const
{
    p.drawEllipse(QPointF(position().x(), position().y()), radius(), radius());
}

QRectF Pin::boundingBox() const
{
    return QRectF(position().x() - radius(), position().y() - radius(), radius() * 2, radius() * 2);
}
