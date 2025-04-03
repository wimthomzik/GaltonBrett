#include "simulationengine.h"
#include "collisionengine.h"
#include "vec2.h"
#include "constants.h"
#include <random>


using namespace global;

SimulationEngine::SimulationEngine()
    : m_collEngine(CollisionEngine()) {}

void SimulationEngine::tick(GaltonBoard &gb, double deltaT, int speedFac)
{
    std::uniform_int_distribution<int> distribution(0,1);
    if(!deltaT)
    {
        deltaT = 0.01;
    }

    for (int i = 0; i < speedFac; i++)
    {
        for (Ball &b : gb.balls())
        {
            Vec2 v0 = b.velocity();
            b.setVelocity(v0 + GRAVITY * deltaT);
            Vec2 resetPos = b.position();
            b.setPosition(b.position() + ((v0 + b.velocity()) / 2) * deltaT); // Da konstante Beschleunigung wird der mittelwert der Beschleunigung verwendet (v0 * v1) / 2

            if(m_collEngine.detect(b, gb.pins()))
            {
                if (gb.balls().back().position().y() > gb.pins()[1].position().y())
                {
                    if (m_spawnCB) (*m_spawnCB)();
                }

                // Handle collision with pin
                b.setVelocity(Vec2());
                if (distribution(m_generator))
                {
                    b.setPosition(b.position() + Vec2(PATTERN_DISTANCE / 2, PATTERN_DISTANCE / 2));
                }
                else
                {
                    b.setPosition(b.position() + Vec2(-(PATTERN_DISTANCE / 2), PATTERN_DISTANCE / 2));
                }
            }
            else if (m_collEngine.detect(b, gb.floor()))
            {

                // Handle Collision with floor
                b.setVelocity({0,0});
                b.setPosition(resetPos);
            }
            else if (m_collEngine.detect(b, gb.balls()))
            {
                // Handle Collision with sleeping Ball
                b.setVelocity({0,0});
                b.setPosition(resetPos);
            }
        }
    }
}

void SimulationEngine::registerSpawnCB(SpawnCB *cb)
{
    m_spawnCB = cb;
}
