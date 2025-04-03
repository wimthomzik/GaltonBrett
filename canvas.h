#ifndef CANVAS_H
#define CANVAS_H

#include "vec2.h"
#include <QWidget>
#include <QVector>
#include <QElapsedTimer>
#include <QTimer>
#include "galtonboard.h"
#include "simulationengine.h"
#include "collisionengine.h"

using Vec2 = wtm::Vec2T<double>;

// Helper functions to convert points to vectors and vice versa
inline Vec2 p2v(const QPointF &p) {return {p.x(), p.y()};}
inline QPointF v2p(const Vec2 &v) {return {v.x(), v.y()};}

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

    void setSpeedFac(int speed) {m_speedFac = speed;}

    int speedFac() {return m_speedFac;}

    void spawnBall();

public slots:
    void startSimulation();
    void resetSimulation();
    void stopSimulation();
    void changePattern(const QString &name);
    void changeSpeedFac(const QString &speed);

private:
    Vec2 m_offset;
    Vec2 m_prevPosition;
    Vec2 m_scale {400, -400};
    std::vector<std::unique_ptr<GaltonBoard>> m_galtonboards;
    size_t m_selectedBoard = 0;
    std::unique_ptr<QElapsedTimer> m_elapsedTimer;
    SimulationEngine m_simEngine;
    CollisionEngine m_collEngine;
    int m_speedFac = 1;

    QVector<Pin> pattern2Pins(const QVector<Vec2> &points) const;
};

#endif // CANVAS_H
