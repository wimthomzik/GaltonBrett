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
    GraphicalPrimitive(const Vec2 &position, const QRectF &boundingBox);
    virtual ~GraphicalPrimitive() = default;

    virtual void draw(QPainter &p) const = 0;

    const Vec2 &position() const {return m_position;}

    const QRectF &boundingBox() const {return m_boundingBox;}

    void boundingBox(const QRectF &newBoundingBox) {m_boundingBox = newBoundingBox;}

    void position(const Vec2 &newPosition) {m_position = newPosition;}

private:
    Vec2 m_position;
    QRectF m_boundingBox;
};

#endif // GRAPHICALPRIMITIVE_H
