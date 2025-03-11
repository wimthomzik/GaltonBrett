#include <staticgraphicalprimitive.h>
#include <vec2.h>

using Vec2 = wtm::Vec2T<double>;

StaticGraphicalPrimitive::StaticGraphicalPrimitive(Vec2 position, QRectF boundingBox)
    : GraphicalPrimitive(position, boundingBox) {}

