#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include "galtonboard.h"
#include "collisionengine.h"
#include <random>

class Canvas;

struct SpawnCB
{
    SpawnCB(Canvas *canvas);

    void operator()();

    Canvas  *canvas;
};

class SimulationEngine
{
public:
    SimulationEngine();

    void tick(GaltonBoard &gb, const double deltaT, int speedFac);

    void registerSpawnCB(SpawnCB *cb);

private:
    CollisionEngine m_collEngine;
    std::default_random_engine m_generator;
    SpawnCB *m_spawnCB = nullptr;
};

#endif // SIMULATIONENGINE_H
