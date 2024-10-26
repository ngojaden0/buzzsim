#include "atmos.h"
#include "constants.h"
#include <stdexcept>

using namespace Constants;

void Atmos::Init(BuzzMemory& buzzMemory)
{
    buzzMemory.Atmos.reset();
}

void Atmos::Update(BuzzMemory& buzzMemory, Entity& missile)
{
    // 1962 International Standard Atmosphere, ISO 2533
    double alt = missile.states.pos[2];

    if(alt >= 0.0 && alt < 11'000.0)
    {
        buzzMemory.Atmos.temp = 288.15 - 0.0065* alt;
        buzzMemory.Atmos.pressure = STANDARD_PRESSURE * std::pow(buzzMemory.Atmos.temp/288.15, 5.2559);
    }
    else if(alt >= 11'000.0 && alt < 80'000.0)
    {
        buzzMemory.Atmos.temp = 216.0;
        buzzMemory.Atmos.pressure = 22'630.0 * std::exp(-0.00015769*(alt - 11'000.0));
    }
    else
    {
        throw std::out_of_range("Altitude out of range: " + std::to_string(alt));
    }

    buzzMemory.Atmos.density = buzzMemory.Atmos.pressure/R_GAS_CONSTANT/buzzMemory.Atmos.temp;
    buzzMemory.Atmos.sonic_speed = sqrt(SPECIFIC_HEAT_AIR*R_GAS_CONSTANT*buzzMemory.Atmos.temp);
    buzzMemory.Atmos.dyn_pressure = buzzMemory.Atmos.density/2*missile.states.vel.norm()*missile.states.vel.norm();
    buzzMemory.Atmos.mach = missile.states.vel.norm()/buzzMemory.Atmos.sonic_speed;
}