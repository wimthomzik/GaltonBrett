#ifndef DYNAMICGRAPHICALPRIMITIVE_H
#define DYNAMICGRAPHICALPRIMITIVE_H

#include <graphicalprimitive.h>
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

class DynamicGraphicalPrimitive : public GraphicalPrimitive
{
public:
    explicit DynamicGraphicalPrimitive() = default;
    explicit DynamicGraphicalPrimitive(Vec2 position, QRectF boundingBox, Vec2 velocity);

    Vec2 getVelocity() const;

    void setVelocity(const wtm::Vec2T<float> &v);

protected:
    Vec2 m_velocity;
};

#endif // DYNAMICGRAPHICALPRIMITIVE_H
