#include <dynamicgraphicalprimitive.h>
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

DynamicGraphicalPrimitive::DynamicGraphicalPrimitive(Vec2 position, QRectF boundingBox, Vec2 velocity)
    : GraphicalPrimitive(position, boundingBox), m_velocity(velocity) {}
