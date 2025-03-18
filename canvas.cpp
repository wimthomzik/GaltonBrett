#include "canvas.h"
#include "galtonboard.h"
#include "vec2.h"
#include <QPainter>
#include <QPaintEvent>
#include "patterfactory.h"
#include "constants.h"
#include "collisionengine.h"
#include "trianglepattern.h"

using Vec2 = wtm::Vec2T<double>;
using namespace constants;

Canvas::Canvas(QWidget *parent)
    : QWidget(parent), m_elapsedTimer(new QElapsedTimer()), m_simEngine(SimulationEngine()), m_collEngine(CollisionEngine()), m_spawnTimer(new QTimer())
{
    startTimer(10);

    connect(m_spawnTimer, &QTimer::timeout, this, &Canvas::spawnBall);
    m_spawnTimer->start(4000);

    m_galtonboards.emplace_back(std::make_unique<GaltonBoard>());
    PatternFactory::Instance().registerPattern(std::make_unique<TrianglePattern>());
    QVector<Vec2> points = PatternFactory::Instance().build("Triangle", 20.0);

    for (const auto &g : m_galtonboards)
    {
        g->pins(pattern2Pins(points));
        g->spawnBall();
    }

}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.translate(m_offset.x(), m_offset.y());
    p.scale(m_scale.x(), -m_scale.y());

    for (const auto &g : m_galtonboards)
    {
        g->draw(p);
    }
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    m_prevPos = q2v(event->pos());
}


void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        Vec2 v {q2v(event->pos())};
        m_offset += v - m_prevPos;
        m_prevPos = v;
        update();
    }
}

void Canvas::wheelEvent(QWheelEvent *event)
{
    Vec2 mousePos = q2v(event->pos());
    double scaleFactor = (event->delta() > 0) ? 1.1 : 0.9;
    m_offset = (mousePos - (mousePos - m_offset) * scaleFactor);
    m_scale *= scaleFactor;
    update();
}

void Canvas::timerEvent(QTimerEvent *)
{

    for (auto &g : m_galtonboards)
    {
        if (g->running())
        {
            m_simEngine.tick(*g, m_elapsedTimer->elapsed() / 1000.);
            m_collEngine.tick(*g);
            update();
        }
    }

    m_elapsedTimer->restart();
}

void Canvas::startSimulation()
{
    for (auto &g : m_galtonboards)
    {
        g->running(true);
    }
    m_elapsedTimer->start();
}

void Canvas::resetSimulation()
{
    for (auto &g : m_galtonboards)
    {
        g->reset();
    }
    update();
}

void Canvas::spawnBall()
{
    for (auto &g : m_galtonboards)
    {
        g->spawnBall();
    }
    update();
}

QVector<Pin> Canvas::pattern2Pins(const QVector<Vec2> &points) const
{
    QVector<Pin> pins;

    for (const auto &v : points)
    {
        pins.append(Pin(v, radius));
    }

    return pins;
}
