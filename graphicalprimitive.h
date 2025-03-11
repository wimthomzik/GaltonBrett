#ifndef GRAPHICALPRIMITIVE_H
#define GRAPHICALPRIMITIVE_H

#include <QObject>
#include <QRectF>
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

class GraphicalPrimitive : public QObject
{
public:
    explicit GraphicalPrimitive() = default;
    explicit GraphicalPrimitive(Vec2 position, QRectF boundingBox);

    virtual void draw() = 0;

    const Vec2 &position() const {return m_position;}

    void position(const Vec2 &newPosition) {m_position = newPosition;}


protected:
    Vec2 m_position;
    QRectF m_boundingBox;
};

#endif // GRAPHICALPRIMITIVE_H
