#ifndef GALTONBOARD_H
#define GALTONBOARD_H

#include <QVector>
#include "pin.h"
#include "ball.h"

class GaltonBoard
{
public:
    explicit GaltonBoard();

    void draw(QPainter &p) const;

    bool running() const {return m_running;}

    void running(bool newState) {m_running = newState;}

    void reset();

    QVector<Ball> &balls() {return m_balls;}

private:
    QVector<Pin> m_pins;
    QVector<Ball> m_balls;
    bool m_running = false;
};

#endif // GALTONBOARD_H
