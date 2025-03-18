#ifndef DYNAMICGRAPHICALPRIMITIVE_H
#define DYNAMICGRAPHICALPRIMITIVE_H

#include "graphicalprimitive.h"
#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

class DynamicGraphicalPrimitive : public GraphicalPrimitive
{
public:
    DynamicGraphicalPrimitive() = default;
    DynamicGraphicalPrimitive(const Vec2 &position, const Vec2 &velocity, const int radius);

    const Vec2 &velocity() const {return m_velocity;}

    void velocity(const Vec2 &newVelocity) {m_velocity = newVelocity;}

private:
    Vec2 m_velocity;
};

#endif // DYNAMICGRAPHICALPRIMITIVE_H
