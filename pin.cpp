#include "pin.h"
#include <QPainter>
#include <QPoint>

Pin::Pin(Vec2 position, QRectF boundingBox)
    : StaticGraphicalPrimitive(position, boundingBox) {}

void Pin::draw(QPainter &p) const
{
    p.drawRect(m_boundingBox);
    QPolygonF triangle;
    triangle << QPoint(boundingBox().center().x(), boundingBox().top())
             << QPoint(boundingBox().left(), boundingBox().bottom())
             << QPoint(boundingBox().right(), boundingBox().bottom());
    p.drawPolygon(triangle);
}
