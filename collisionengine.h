#ifndef COLLISIONENGINE_H
#define COLLISIONENGINE_H

#include "galtonboard.h"

class CollisionEngine
{
public:
    CollisionEngine() = default;

    void tick(GaltonBoard &gb);
};

#endif // COLLISIONENGINE_H
