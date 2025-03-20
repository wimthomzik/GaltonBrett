#include <dynamicgraphicalprimitive.h>
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

DynamicGraphicalPrimitive::DynamicGraphicalPrimitive(const Vec2 &position, const Vec2 &velocity)
    : GraphicalPrimitive(position), m_velocity(velocity) {}
