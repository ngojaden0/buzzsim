#include "prop.h"
#include "math_utils.h"
#include "constants.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void Prop::Init(std::unique_ptr<BuzzMemory> buzzMemory)
{
    buzzMemory->prop.reset();

    // Use SAM data by zipfel
    // Use dt and total time to interpolate mass, xcg, and thrust
    // Initially store table data into vector
    buzzMemory->prop.specific_impulse = 260.0;   // sec
    buzzMemory->prop.mass = 300.0;               // kg
    buzzMemory->prop.xcg = 2.9;                  // m

    // TODO: Ae in config, use SAM
    Ae = 0.06;                                  // m
}

void Prop::Update(std::unique_ptr<BuzzMemory> buzzMemory, std::unique_ptr<Entity> missile)
{
    // TODO: Read from tables, set zero for now
    double mass_table = 0.0;
    double xcg_table = 0.0;
    double thrust_table = 0.0;

    buzzMemory->prop.mass = Utils::Interpolate(buzzMemory->totalTime, buzzMemory->dt, mass_table);
    buzzMemory->prop.xcg = Utils::Interpolate(buzzMemory->totalTime, buzzMemory->dt, xcg_table);

    double fsl = Utils::Interpolate(buzzMemory->totalTime, buzzMemory->dt, thrust_table);

    // Account thrust at altitude
    buzzMemory->prop.thrust = fsl + (Constants::STANDARD_PRESSURE - buzzMemory->atmos.pressure)*Ae;
}