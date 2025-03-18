#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

namespace constants
{
    constexpr int radius { 20 };
    const Vec2 gravity {0, 9.80665};
    const Vec2 startPosBall {175, 10};
    const Vec2 startPosPin {175, 40};
    constexpr size_t distance {50};
    constexpr size_t numRow {6};
}

#endif // CONSTANTS_H
