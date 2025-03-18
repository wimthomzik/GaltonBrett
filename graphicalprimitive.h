#ifndef GRAPHICALPRIMITIVE_H
#define GRAPHICALPRIMITIVE_H

#include <QRect>
#include <QPainter>
#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

class GraphicalPrimitive
{
public:
    GraphicalPrimitive() = default;
    GraphicalPrimitive(const Vec2 &position, const int radius);
    virtual ~GraphicalPrimitive() = default;

    virtual void draw(QPainter &p) const = 0;

    virtual QRectF boundingBox() const = 0;

    const Vec2 &position() const {return m_position;}

    void position(const Vec2 &newPosition) {m_position = newPosition;}

    int radius() const {return m_radius;}

    void radius(const int radius) {m_radius = radius;}

private:
    Vec2 m_position;
    int m_radius;
};

#endif // GRAPHICALPRIMITIVE_H
