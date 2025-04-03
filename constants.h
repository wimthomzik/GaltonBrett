#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

namespace global
{
    const Vec2 GRAVITY {0, 9.80665};
    constexpr double GB_WIDTH = 0.8;
    constexpr double GB_HEIGHT = 1.4;
    constexpr double BALL_RADIUS = .02;
    constexpr double PATTERN_DISTANCE = 5 * BALL_RADIUS;
}

#endif // CONSTANTS_H
