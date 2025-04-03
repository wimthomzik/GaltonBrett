#ifndef BALL_H
#define BALL_H

#include "dynamicgraphicalprimitive.h"
#include <QPainter>
#include "constants.h"

using namespace global;

class Ball : public DynamicGraphicalPrimitive
{
public:
    Ball() = default;
    Ball(const Vec2 &position, const Vec2 &setVelocity, const double radius = BALL_RADIUS); // Change BALL_RADIUS in constants.h

    void draw(QPainter &p) const override;

    QRectF boundingBox() const override;

    double radius() const {return m_radius;}

    void setRadius(const double radius) {m_radius = radius;}

    double m_radius;
};

#endif // BALL_H
