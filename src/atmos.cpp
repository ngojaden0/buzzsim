#include "atmos.h"
#include "constants.h"
#include <stdexcept>

using namespace Constants;

void Atmos::Init(std::unique_ptr<BuzzMemory> buzzMemory)
{
    buzzMemory->atmos.reset();
}

void Atmos::Update(std::unique_ptr<BuzzMemory> buzzMemory, std::unique_ptr<Entity> missile)
{
    // 1962 International Standard atmosphere, ISO 2533
    double alt = missile->states.pos[2];

    if(alt >= 0.0 && alt < 11'000.0)
    {
        buzzMemory->atmos.temp = 288.15 - 0.0065* alt;
        buzzMemory->atmos.pressure = STANDARD_PRESSURE * std::pow(buzzMemory->atmos.temp/288.15, 5.2559);
    }
    else if(alt >= 11'000.0 && alt < 80'000.0)
    {
        buzzMemory->atmos.temp = 216.0;
        buzzMemory->atmos.pressure = 22'630.0 * std::exp(-0.00015769*(alt - 11'000.0));
    }
    else
    {
        throw std::out_of_range("Altitude out of range: " + std::to_string(alt));
    }

    buzzMemory->atmos.density = buzzMemory->atmos.pressure/R_GAS_CONSTANT/buzzMemory->atmos.temp;
    buzzMemory->atmos.sonic_speed = sqrt(SPECIFIC_HEAT_AIR*R_GAS_CONSTANT*buzzMemory->atmos.temp);
    buzzMemory->atmos.dyn_pressure = buzzMemory->atmos.density/2*missile->states.vel.norm()*missile->states.vel.norm();
    buzzMemory->atmos.mach = missile->states.vel.norm()/buzzMemory->atmos.sonic_speed;
}