#ifndef BALL_H
#define BALL_H

#include "dynamicgraphicalprimitive.h"
#include <QPainter>

class Ball : public DynamicGraphicalPrimitive
{
public:
    Ball() = default;
    Ball(const Vec2 &position, const Vec2 &velocity, const double radius = 17.);

    void draw(QPainter &p) const override;

    QRectF boundingBox() const override;

    double radius() const {return m_radius;}

    void radius(const int radius) {m_radius = radius;}

    double m_radius;
};

#endif // BALL_H
