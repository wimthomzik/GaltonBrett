#include "graphicalprimitive.h"
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

GraphicalPrimitive::GraphicalPrimitive(const Vec2 &position, const QRectF &boundingBox)
    : m_position(position), m_boundingBox(boundingBox) {}


