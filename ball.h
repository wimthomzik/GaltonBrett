#ifndef BALL_H
#define BALL_H

#include <dynamicgraphicalprimitive.h>


class Ball : public DynamicGraphicalPrimitive
{
public:
    explicit Ball() = default;
    explicit Ball(QPointF position, QSizeF size, QRectF boundingBox, wtm::Vec2T<float> velocity);

    void draw() override;
};

#endif // BALL_H
