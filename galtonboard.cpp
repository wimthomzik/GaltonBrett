#include "galtonboard.h"
#include "pin.h"
#include "ball.h"
#include "constants.h"
#include <QVector>

using namespace constants;

GaltonBoard::GaltonBoard()
{
    QVector<Ball> balls;
    balls.append(Ball(startPosBall, {startPosBall.x(), startPosBall.y(), rectSize, rectSize}, {0, 0}));
    m_balls = balls;

    QVector<Pin> pins;
    pins.append(Pin(startPosPin, {startPosPin.x(), startPosPin.y(), rectSize, rectSize}));
    m_pins = pins;
}

void GaltonBoard::draw(QPainter &p) const
{
    for (const Pin &pin : m_pins)
    {
        pin.draw(p);
    }

    for (const Ball &ball : m_balls)
    {
        ball.draw(p);
    }
}

void GaltonBoard::reset()
{
    running(false);
    for (Ball &b : m_balls)
    {
        b.velocity({0,0});
        b.position(startPosBall);
        b.boundingBox({startPosBall.x(), startPosBall.y(), rectSize, rectSize});
    }
}
