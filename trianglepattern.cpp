#include "trianglepattern.h"
#include "vec2.h"
#include "constants.h"

using Vec2 = wtm::Vec2T<double>;

QVector<Vec2> TrianglePattern::generate(double distance) const
{
    QVector<Vec2> v;

    for (size_t row = 0; row < 6; row++)
    {
        for (size_t col = 0; col <= row; col++)
        {
            double x = col * distance - (row * distance / 2);
            double y = row * distance * 0.886;
            v.append({x,y});
        }
     }

     return v;
}
