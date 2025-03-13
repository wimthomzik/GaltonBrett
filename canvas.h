#ifndef CANVAS_H
#define CANVAS_H

#include "vec2.h"
#include <QWidget>
#include <QVector>
#include <QElapsedTimer>
#include "galtonboard.h"
#include "simulationengine.h"

using Vec2 = wtm::Vec2T<double>;

inline Vec2 q2v(const QPoint &p) {return Vec2(p.x(), p.y());}

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

public slots:
    void startSimulation();
    void resetSimulation();

private:
    Vec2 m_offset;
    Vec2 m_prevPos;
    Vec2 m_scale {2, -2};
    QVector<GaltonBoard> m_galtonboards; // multiple
    QElapsedTimer *m_elapsedTimer;
    SimulationEngine m_simEngine;
};

#endif // CANVAS_H
