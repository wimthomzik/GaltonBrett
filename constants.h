#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "vec2.h"

using Vec2 = wtm::Vec2T<double>;

namespace constants
{
    const Vec2 gravity {0, 9.80665};
    const Vec2 startPosBall {175, 10};
    constexpr size_t distance {50};
}

#endif // CONSTANTS_H
