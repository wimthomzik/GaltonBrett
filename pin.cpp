#include "pin.h"
#include <QPainter>
#include <QPoint>

Pin::Pin(const Vec2 &position, const QRectF &boundingBox)
    : StaticGraphicalPrimitive(position, boundingBox) {}

void Pin::draw(QPainter &p) const
{
    p.save();
    p.translate(position().x(), position().y());
    p.drawRect(boundingBox());
    p.restore();
}
