#ifndef PIN_H
#define PIN_H

#include "staticgraphicalprimitive.h"
#include <QPolygon>
#include <QPainter>


class Pin : StaticGraphicalPrimitive
{
public:
    explicit Pin() = default;
    explicit Pin(const Vec2 &position, const QRectF &boundingBox);

    void draw(QPainter &p) const override;
};

#endif // PIN_H
