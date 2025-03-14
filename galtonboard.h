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

    void reset();

    bool running() const {return m_running;}

    void running(const bool newState) {m_running = newState;}

    QVector<Ball> &balls() {return m_balls;}

private:
    QVector<Pin> m_pins;
    QVector<Ball> m_balls;
    bool m_running = false;
};

#endif // GALTONBOARD_H
