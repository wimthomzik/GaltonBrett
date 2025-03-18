#ifndef BALL_H
#define BALL_H

#include "dynamicgraphicalprimitive.h"
#include <QPainter>

class Ball : public DynamicGraphicalPrimitive
{
public:
    Ball() = default;
    Ball(const Vec2 &position, const Vec2 &velocity, const int radius);

    void draw(QPainter &p) const override;

    QRectF boundingBox() const override;
};

#endif // BALL_H
