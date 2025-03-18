#ifndef PATTERNGENERATOR_H
#define PATTERNGENERATOR_H

#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

class PatternGenerator
{
public:
    virtual ~PatternGenerator() = default;

    virtual QString         name() const  = 0;
    virtual QVector<Vec2>   generate(double distance) const = 0;
};

#endif // PATTERNGENERATOR_H
