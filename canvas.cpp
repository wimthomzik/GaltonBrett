#include "canvas.h"
#include "galtonboard.h"
#include "vec2.h"
#include <QPainter>
#include <QPaintEvent>
#include "patternfactory.h"
#include "constants.h"
#include "trianglepattern.h"

using Vec2 = wtm::Vec2T<double>;
using namespace constants;

Canvas::Canvas(QWidget *parent)
    : QWidget(parent), m_elapsedTimer(std::make_unique<QElapsedTimer>()), m_simEngine(SimulationEngine()), m_spawnTimer(std::make_unique<QTimer>())
{
    startTimer(10);

    connect(m_spawnTimer.get(), &QTimer::timeout, this, &Canvas::spawnBall);

    m_galtonboards.emplace_back(std::make_unique<GaltonBoard>(Vec2()));
    m_galtonboards.emplace_back(std::make_unique<GaltonBoard>(Vec2(202, 0)));
}

void Canvas::changePattern(const QString &name)
{
    QVector<Vec2> points = PatternFactory::Instance().build(name, 20.0);


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

    for (size_t i = 0; i < m_galtonboards.size(); i++)
    {
        if (i == m_selected)
        {
            p.setPen(Qt::red);
        }
        m_galtonboards[i]->draw(p);
        p.setPen(Qt::black);
    }
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    m_prevPos = p2v(event->pos());
    QPoint mousePos = v2p(p2v(event->pos()) - m_offset);
    if (!m_galtonboards[m_selected]->boundingBox().contains(mousePos))
    {
        for (size_t i = 0; i < m_galtonboards.size(); i++)
        {
            if (m_galtonboards[i]->boundingBox().contains(mousePos) and i != m_selected) {
                m_selected = i;
                update();
            }
        }
    }
}


void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        Vec2 v {p2v(event->pos())};
        m_offset += v - m_prevPos;
        m_prevPos = v;
        update();
    }
}

void Canvas::wheelEvent(QWheelEvent *event)
{
    Vec2 mousePos = p2v(event->pos());
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
            update();
        }
    }
    m_elapsedTimer->restart();
}

void Canvas::startSimulation()
{
    m_galtonboards[m_selected]->running(true);
    m_elapsedTimer->start();
    m_spawnTimer->start(3000);
}

void Canvas::resetSimulation()
{
    m_galtonboards[m_selected]->reset();
    update();
}

void Canvas::stopSimulation()
{
    m_galtonboards[m_selected]->running(false);
    update();
}

void Canvas::spawnBall()
{
    for (auto &g : m_galtonboards)
    {
        if (g->running())
        {
            g->spawnBall();
        }
    }
    update();
}

QVector<Pin> Canvas::pattern2Pins(const QVector<Vec2> &points) const
{
    QVector<Pin> pins;

    for (const auto &v : points)
    {
        pins.append(Pin(v + Vec2(0, 30.))); // lowering pins so that ball start 30 over pins
    }

    return pins;
}
