#include "canvas.h"
#include "galtonboard.h"
#include "vec2.h"
#include <QPainter>
#include <QPaintEvent>

using Vec2 = wtm::Vec2T<double>;

Canvas::Canvas(QWidget *parent)
    : QWidget(parent), m_elapsedTimer(new QElapsedTimer()), m_simEngine(SimulationEngine())
{
    startTimer(10);
    m_galtonboards.append(GaltonBoard());
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.translate(m_offset.x(), m_offset.y());
    p.scale(m_scale.x(), -m_scale.y());

    for (const GaltonBoard &g : m_galtonboards)
    {
        g.draw(p);
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

    for (GaltonBoard &g : m_galtonboards)
    {
        if (g.running())
        {
            m_simEngine.tick(g, m_elapsedTimer->elapsed() / 1000.);
            // KollEngine(GaltonBoard)
            update();
        }
    }

    m_elapsedTimer->restart();
}

void Canvas::startSimulation()
{
    for (GaltonBoard &g : m_galtonboards)
    {
        g.running(true);
    }
    m_elapsedTimer->start();
}

void Canvas::resetSimulation()
{
    for (GaltonBoard &g : m_galtonboards)
    {
        g.reset();
    }
    update();
}

