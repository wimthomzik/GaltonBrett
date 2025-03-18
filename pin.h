#ifndef PIN_H
#define PIN_H

#include "staticgraphicalprimitive.h"
#include <QPolygon>
#include <QPainter>


class Pin : public StaticGraphicalPrimitive
{
public:
    Pin() = default;
    Pin(const Vec2 &position, const int radius);

    void draw(QPainter &p) const override;

    QRectF boundingBox() const override;
};

#endif // PIN_H
