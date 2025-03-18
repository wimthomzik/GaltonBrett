#include "graphicalprimitive.h"
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

GraphicalPrimitive::GraphicalPrimitive(const Vec2 &position, const int radius)
    : m_position(position), m_radius(radius) {}


