#ifndef PIN_H
#define PIN_H

#include "staticgraphicalprimitive.h"
#include <QPolygon>
#include <QPainter>


class Pin : StaticGraphicalPrimitive
{
public:
    explicit Pin() = default;
    explicit Pin(Vec2 position, QRectF boundingBox);

    void draw(QPainter &p) const override;
};

#endif // PIN_H
