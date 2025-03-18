#ifndef TRIANGLEPATTERN_H
#define TRIANGLEPATTERN_H

#include "patterngenerator.h"

class TrianglePattern : public PatternGenerator
{
public:
    QString         name() const override {return "Triangle";}
    QVector<Vec2>   generate(double distance) const override;
};

#endif // TRIANGLEPATTERN_H
