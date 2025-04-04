#include "canvas.h"
#include "galtonboard.h"
#include "vec2.h"
#include <QPainter>
#include <QPaintEvent>
#include "patternfactory.h"
#include "constants.h"
#include "trianglepattern.h"

using Vec2 = wtm::Vec2T<double>;
using namespace global;

//SpawnCB::SpawnCB(Canvas *canvas) : canvas(canvas) {}

//void SpawnCB::operator()()
//{
//    canvas->spawnBall();
//}

Canvas::Canvas(QWidget *parent)
    : QWidget(parent), m_elapsedTimer(std::make_unique<QElapsedTimer>()), m_simEngine(SimulationEngine())/*, m_spawnTimer(std::make_unique<QTimer>())*/
{
    startTimer(10);

//    m_simEngine.registerSpawnCB(new SpawnCB(this));

    m_galtonboards.emplace_back(std::make_unique<GaltonBoard>(Vec2()));
    m_galtonboards.emplace_back(std::make_unique<GaltonBoard>(Vec2(GB_WIDTH + .01, 0)));
    m_galtonboards.emplace_back(std::make_unique<GaltonBoard>(Vec2((GB_WIDTH + .01) * 2, 0)));
}

// Changes patter of all galton boards
void Canvas::changePattern(const QString &name)
{
    QVector<Vec2> points = PatternFactory::Instance().build(name, PATTERN_DISTANCE);

    for (const auto &g : m_galtonboards)
    {
        g->setPins(pattern2Pins(points));
        // Spawn inital Ball
        g->spawnBall();
    }
}

// Changes speed factor of all galton boards
void Canvas::changeSpeedFac(const QString &speed)
{
    setSpeedFac(speed.toInt());
}

// Draw all galton boards
void Canvas::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen pen;

    // Set cosmetic pen to not scale thickness of drawn lines
    pen.setCosmetic(true);
    p.setPen(pen);

    p.translate(m_offset.x(), m_offset.y());
    p.scale(m_scale.x(), -m_scale.y());

    for (size_t i = 0; i < m_galtonboards.size(); i++)
    {
        // Mark selectes galton board red
        if (i == m_selectedBoard)
        {
            pen.setColor(Qt::red);
            p.setPen(pen);
        }
        m_galtonboards[i]->draw(p);
        pen.setColor(Qt::black);
        p.setPen(pen);
    }
}

// Sets selectedBoard and saves prevPosition for translation
void Canvas::mousePressEvent(QMouseEvent *event)
{
    m_prevPosition = p2v(event->pos());

    // Transform screen coordinates to world coordinates by removing scaling and translating
    QPointF mousePos = v2p(p2v(event->pos()) - m_offset);
    mousePos = QPointF(mousePos.rx() / m_scale.x(), mousePos.ry() / -m_scale.y());

    if (!m_galtonboards[m_selectedBoard]->boundingBox().contains(mousePos))
    {
        for (size_t i = 0; i < m_galtonboards.size(); i++)
        {
            if (m_galtonboards[i]->boundingBox().contains(mousePos) and i != m_selectedBoard) {
                m_selectedBoard = i;
                update();
            }
        }
    }
}

// Sets new offset/translation
void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        Vec2 v {p2v(event->pos())};
        m_offset += v - m_prevPosition;
        m_prevPosition = v;
        update();
    }
}

// Scales around mouse pointer
void Canvas::wheelEvent(QWheelEvent *event)
{
    Vec2 mousePos = p2v(event->pos());
    double scaleFactor = (event->delta() > 0) ? 1.1 : 0.9;
    m_offset = (mousePos - (mousePos - m_offset) * scaleFactor);
    m_scale *= scaleFactor;
    update();
}

// Updates galtonboards regularly
void Canvas::timerEvent(QTimerEvent *)
{
    double  dt = double(m_elapsedTimer->elapsed()) / 1000.;

    for (auto &g : m_galtonboards)
    {
        if (g->running())
        {
            m_simEngine.tick(*g, dt, m_speedFac);
            update();
        }
    }
    m_elapsedTimer->restart();
}

void Canvas::startSimulation()
{
    m_galtonboards[m_selectedBoard]->setRunning(true);
    m_elapsedTimer->start();
}

void Canvas::resetSimulation()
{
    m_galtonboards[m_selectedBoard]->reset();
    update();
}

void Canvas::stopSimulation()
{
    m_galtonboards[m_selectedBoard]->setRunning(false);
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
        pins.append(Pin(v + Vec2(0, PATTERN_DISTANCE))); // Lowering starting position to not collide with ball right away
    }

    return pins;
}
