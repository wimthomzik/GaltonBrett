#ifndef CANVAS_H
#define CANVAS_H

#include "vec2.h"
#include <QWidget>
#include <QVector>
#include <QElapsedTimer>
#include "galtonboard.h"
#include "simulationengine.h"
#include "collisionengine.h"

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
    std::vector<std::unique_ptr<GaltonBoard>> m_galtonboards;
    QElapsedTimer *m_elapsedTimer;
    SimulationEngine m_simEngine;
    CollisionEngine m_collEngine;

    QVector<Pin> pattern2Pins(const QVector<Vec2> &points) const;
};

#endif // CANVAS_H
