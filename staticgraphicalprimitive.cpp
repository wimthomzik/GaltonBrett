#include <staticgraphicalprimitive.h>
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

StaticGraphicalPrimitive::StaticGraphicalPrimitive(const Vec2 &position)
    : GraphicalPrimitive(position) {}

