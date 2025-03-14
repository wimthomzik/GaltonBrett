#ifndef BALL_H
#define BALL_H

#include "dynamicgraphicalprimitive.h"
#include <QPainter>

class Ball : public DynamicGraphicalPrimitive
{
public:
    Ball() = default;
    Ball(const Vec2 &position, const QRectF &boundingBox, const Vec2 &velocity);

    void draw(QPainter &p) const override;

private:

};

#endif // BALL_H
