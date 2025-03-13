#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include "galtonboard.h"

class SimulationEngine
{
public:
    SimulationEngine() = default;

    void tick(GaltonBoard *gb, double deltaT);
};

#endif // SIMULATIONENGINE_H
