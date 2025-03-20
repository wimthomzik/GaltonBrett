#ifndef GALTONBOARD_H
#define GALTONBOARD_H

#include <QVector>
#include "pin.h"
#include "ball.h"
#include "floor.h"
#include <memory>
#include "constants.h"

using namespace constants;

class GaltonBoard : public StaticGraphicalPrimitive
{
public:
    GaltonBoard() = default;

    GaltonBoard(const Vec2 &position);

    void draw(QPainter &p) const override;

     QRectF boundingBox() const override;

    void reset();

    bool running() const {return m_running;}

    void running(const bool newState) {m_running = newState;}

    QVector<Ball> &balls() {return m_balls;}

    void spawnBall() {m_balls.append(Ball({0, 0}, {0, 0}));}

    void pins(const QVector<Pin> &pins) {m_pins = pins;}

    QVector<Pin> &pins() {return m_pins;}

    Floor &floor() {return m_floor;}

private:
    QVector<Pin> m_pins;
    QVector<Ball> m_balls;
    Floor m_floor;
    bool m_running = false;
};

#endif // GALTONBOARD_H
