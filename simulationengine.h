#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include "galtonboard.h"
#include "collisionengine.h"
#include <random>

class SimulationEngine
{
public:
    SimulationEngine();

    void tick(GaltonBoard &gb, const double deltaT);

private:
    CollisionEngine m_collEngine;
    std::default_random_engine m_generator;
};

#endif // SIMULATIONENGINE_H
