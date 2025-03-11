#ifndef STATICGRAPHICALPRIMITIVE_H
#define STATICGRAPHICALPRIMITIVE_H

#include <graphicalprimitive.h>
#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

class StaticGraphicalPrimitive : public GraphicalPrimitive
{
public:
    explicit StaticGraphicalPrimitive() = default;
    explicit StaticGraphicalPrimitive(Vec2 position, QRectF boundingBox);
};

#endif // STATICGRAPHICALPRIMITIVE_H
