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

inline Vec2 p2v(const QPoint &p) {return Vec2(p.x(), p.y());}
inline QPoint v2p(const Vec2 &v) {return QPoint(v.x(), v.y());}

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
    void stopSimulation();
    void changePattern(const QString &name);

private slots:
    void spawnBall();

private:
    Vec2 m_offset;
    Vec2 m_prevPos;
    Vec2 m_scale {1, -1};
    std::vector<std::unique_ptr<GaltonBoard>> m_galtonboards;
    size_t m_selected = 0;
    std::unique_ptr<QElapsedTimer> m_elapsedTimer;
    SimulationEngine m_simEngine;
    CollisionEngine m_collEngine;
    std::unique_ptr<QTimer> m_spawnTimer;

    QVector<Pin> pattern2Pins(const QVector<Vec2> &points) const;
};

#endif // CANVAS_H
