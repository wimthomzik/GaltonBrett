#ifndef BALL_H
#define BALL_H

#include "dynamicgraphicalprimitive.h"
#include <QPainter>

class Ball : public DynamicGraphicalPrimitive
{
public:
    explicit Ball() = default;
    explicit Ball(Vec2 position, QRectF boundingBox, Vec2 velocity);

    void draw(QPainter &p) const override;

private:

};

#endif // BALL_H
