#ifndef FLOOR_H
#define FLOOR_H

#include "staticgraphicalprimitive.h"

class Floor : public StaticGraphicalPrimitive
{
public:
    Floor() = default;
    Floor(const Vec2 &position);

    void draw(QPainter &p) const override;

    QRectF boundingBox() const override;
};

#endif // FLOOR_H
