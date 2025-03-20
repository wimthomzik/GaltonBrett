#ifndef PIN_H
#define PIN_H

#include "staticgraphicalprimitive.h"
#include <QPolygon>
#include <QPainter>


class Pin : public StaticGraphicalPrimitive
{
public:

    Pin() = default;
    Pin(const Vec2 &position, const double radius = 17.);

    void draw(QPainter &p) const override;

    QRectF boundingBox() const override;

    int radius() const {return m_radius;}

    void radius(const int radius) {m_radius = radius;}

private:
    double m_radius;

};

#endif // PIN_H
