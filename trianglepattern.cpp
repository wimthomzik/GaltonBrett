#include "trianglepattern.h"
#include "vec2.h"
#include "constants.h"

using Vec2 = wtm::Vec2T<double>;
using namespace constants;

QVector<Vec2> TrianglePattern::generate(double distance) const
{
    QVector<Vec2> v;

    for (size_t row = 0; row < numRow; row++)
    {
        for (size_t col = 0; col <= row; col++)
        {
            double x = col * distance - (row * distance / 2);
            double y = row * distance;
            v.append({x,y});
        }
     }

     return v;
}
