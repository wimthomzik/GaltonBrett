#include "pin.h"
#include <QPainter>
#include <QPoint>
#include "constants.h"

Pin::Pin(const Vec2 &position, const int radius)
    : StaticGraphicalPrimitive(position, radius) {}

void Pin::draw(QPainter &p) const
{
    p.drawEllipse(position().x(), position().y(), radius() / 2, radius() / 2);
}

QRectF Pin::boundingBox() const
{
    return QRectF(position().x() - radius(), position().y() - radius(), radius() / 2, radius() / 2);
}
