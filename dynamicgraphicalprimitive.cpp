#include <dynamicgraphicalprimitive.h>
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

DynamicGraphicalPrimitive::DynamicGraphicalPrimitive(const Vec2 &position, const QRectF &boundingBox, const Vec2 &velocity)
    : GraphicalPrimitive(position, boundingBox), m_velocity(velocity) {}
