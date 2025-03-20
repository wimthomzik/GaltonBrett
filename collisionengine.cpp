#include "collisionengine.h"

bool CollisionEngine::detect(const Ball &b, const QVector<Pin> &pins) const
{
    for (auto const &p : pins)
    {
        if (p.boundingBox().intersects(b.boundingBox()))
        {
            return true;
        }
    }
    return false;
}

bool CollisionEngine::detect(const Ball &b, const QVector<Ball> &balls) const
{
    for (auto const &ball : balls)
    {
        if (&ball != &b and ball.boundingBox().intersects(b.boundingBox()))
        {
            return true;
        }
    }
    return false;
}

bool CollisionEngine::detect(const Ball &b, const Floor &f) const
{
    return f.boundingBox().intersects(b.boundingBox());
}


