#include "pin.h"
#include <QPainter>
#include <QPoint>

Pin::Pin(const Vec2 &position, const QRectF &boundingBox)
    : StaticGraphicalPrimitive(position, boundingBox) {}

void Pin::draw(QPainter &p) const
{
    p.drawRect(boundingBox());
    QPolygonF triangle;
    triangle << QPoint(boundingBox().center().x(), boundingBox().top())
             << QPoint(boundingBox().left(), boundingBox().bottom())
             << QPoint(boundingBox().right(), boundingBox().bottom());
    p.drawPolygon(triangle);
}
