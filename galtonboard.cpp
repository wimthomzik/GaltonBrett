#include "galtonboard.h"
#include "pin.h"
#include "ball.h"
#include "constants.h"
#include <QVector>

using namespace constants;

GaltonBoard::GaltonBoard() {}

void GaltonBoard::draw(QPainter &p) const
{
    p.translate(startPosPin.x(), startPosPin.y());
    for (const auto &pin : m_pins)
    {
        pin.draw(p);
    }
    p.translate(-startPosPin.x(), -startPosPin.y());

    for (const auto &ball : m_balls)
    {
        ball.draw(p);
    }
}

void GaltonBoard::reset()
{
    running(false);
    m_balls.clear();
    ball();
}
