#ifndef PIN_H
#define PIN_H

#include "staticgraphicalprimitive.h"
#include <QPolygon>
#include <QPainter>
#include "constants.h"

using namespace global;

class Pin : public StaticGraphicalPrimitive
{
public:
    Pin() = default;
    Pin(const Vec2 &position, const double radius = BALL_RADIUS);

    void draw(QPainter &p) const override;

    QRectF boundingBox() const override;

    double radius() const {return m_radius;}

    void setRadius(const double radius) {m_radius = radius;}

private:
    double m_radius;
};

#endif // PIN_H
