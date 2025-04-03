#include "galtonboard.h"
#include "pin.h"
#include "ball.h"
#include "constants.h"
#include <QVector>

GaltonBoard::GaltonBoard(const Vec2 &position)
    : StaticGraphicalPrimitive(position), m_floor(Floor(Vec2(-GB_WIDTH / 2, position.y() + GB_HEIGHT * 0.95), GB_WIDTH)) {}

void GaltonBoard::draw(QPainter &p) const
{
    //p.drawRect(boundingBox());
    p.translate(position().x(), position().y());
    p.translate(GB_WIDTH / 2., BALL_RADIUS);
    for (const auto &pin : m_pins)
    {
        pin.draw(p); 
    }

    for (const auto &ball : m_balls)
    {
        ball.draw(p);
    }
    m_floor.draw(p);
    p.translate(-GB_WIDTH / 2., -BALL_RADIUS);
    p.translate(-position().x(), -position().y());
}

void GaltonBoard::reset()
{
    setRunning(false);
    m_balls.clear();
    spawnBall();
}

QRectF GaltonBoard::boundingBox() const
{
    return QRectF(position().x(), position().y(), GB_WIDTH, GB_HEIGHT);
}

