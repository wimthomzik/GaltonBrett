#include "simulationengine.h"
#include "collisionengine.h"
#include "vec2.h"
#include "constants.h"
#include <random>


using namespace constants;

SimulationEngine::SimulationEngine()
    : m_collEngine(CollisionEngine()) {}

void SimulationEngine::tick(GaltonBoard &gb, double deltaT)
{
    std::uniform_int_distribution<int> distribution(0,1);

    for (Ball &b : gb.balls())
    {
        Vec2 v0 = b.velocity();
        b.velocity(v0 + gravity * 100 * deltaT);
        Vec2 resetPos = b.position();
        b.position(b.position() + ((v0 + b.velocity()) / 2) * deltaT); // Da konstante Beschleunigung wird der mittelwert der Beschleunigung verwendet (v0 * v1) / 2

        if(m_collEngine.detect(b, gb.pins()))
        {
            // Handle collision with pin
            b.velocity(Vec2());
            if (distribution(m_generator))
            {
                b.position(b.position() + Vec2(10., 9.4));
            }
            else
            {
                b.position(b.position() + Vec2(-10., 9.4));
            }
        }
        else if (m_collEngine.detect(b, gb.floor()))
        {
            // Handle Collision with floor
            b.velocity({0,0});
            b.position(resetPos);
        }
        else if (m_collEngine.detect(b, gb.balls()))
        {
            // Handle Collision with sleeping Ball
            b.velocity({0,0});
            b.position(resetPos);
        }
    }
}
