#ifndef GRAPHICALPRIMITIVE_H
#define GRAPHICALPRIMITIVE_H

#include <QRectF>
#include <QPainter>
#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

class GraphicalPrimitive
{
public:
    GraphicalPrimitive() = default;
    GraphicalPrimitive(const Vec2 &position);
    virtual ~GraphicalPrimitive() = default;

    virtual void draw(QPainter &p) const = 0;

    virtual QRectF boundingBox() const = 0;

    const Vec2 &position() const {return m_position;}

    void setPosition(const Vec2 &newPosition) {m_position = newPosition;}

private:
    Vec2 m_position;
};

#endif // GRAPHICALPRIMITIVE_H
