#ifndef STATICGRAPHICALPRIMITIVE_H
#define STATICGRAPHICALPRIMITIVE_H

#include <graphicalprimitive.h>
#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

class StaticGraphicalPrimitive : public GraphicalPrimitive
{
public:
    StaticGraphicalPrimitive() = default;
    StaticGraphicalPrimitive(const Vec2 &position);
};

#endif // STATICGRAPHICALPRIMITIVE_H
