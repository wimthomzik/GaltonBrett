#include "galtonboard.h"
#include "pin.h"
#include "ball.h"
#include "constants.h"
#include <QVector>

using namespace constants;

GaltonBoard::GaltonBoard(const Vec2 &position)
    : StaticGraphicalPrimitive(position), m_floor(Floor(Vec2(-100., 190.))) {}

void GaltonBoard::draw(QPainter &p) const
{
    p.drawRect(boundingBox());
    p.translate(position().x(), position().y());
    for (const auto &pin : m_pins)
    {
        pin.draw(p); 
    }

    for (const auto &ball : m_balls)
    {
        ball.draw(p);
    }
    m_floor.draw(p);
    p.translate(-position().x(), -position().y());
}

void GaltonBoard::reset()
{
    running(false);
    m_balls.clear();
    spawnBall();
}

QRectF GaltonBoard::boundingBox() const
{
    return QRectF(position().x(), position().y(), 200, 200);
}

