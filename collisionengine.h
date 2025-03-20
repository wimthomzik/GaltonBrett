#ifndef COLLISIONENGINE_H
#define COLLISIONENGINE_H

#include "galtonboard.h"

class CollisionEngine
{
public:
    CollisionEngine() = default;

    bool detect(const Ball &b, const QVector<Pin> &pins) const;

    bool detect(const Ball &b, const QVector<Ball> &balls) const;

    bool detect(const Ball &b, const Floor &floor) const;
};

#endif // COLLISIONENGINE_H
