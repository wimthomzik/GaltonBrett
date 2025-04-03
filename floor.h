#ifndef FLOOR_H
#define FLOOR_H

#include "staticgraphicalprimitive.h"

class Floor : public StaticGraphicalPrimitive
{
public:
    Floor() = default;
    Floor(const Vec2 &position, const double width);

    void draw(QPainter &p) const override;

    QRectF boundingBox() const override;

private:
    double m_width;
};

#endif // FLOOR_H
