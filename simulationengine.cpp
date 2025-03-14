#include "simulationengine.h"
#include "vec2.h"
#include "constants.h"

void SimulationEngine::tick(GaltonBoard &gb, double deltaT)
{
    for (Ball &b : gb.balls())
    {
        Vec2 v0 = b.velocity();
        b.velocity(v0 + constants::gravity * deltaT);
        b.position(b.position() + ((v0 + b.velocity()) / 2) * deltaT);
    }
}
