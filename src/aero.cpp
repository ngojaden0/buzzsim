#include "aero.h"
#include <cmath>

void Aero::Init(BuzzMemory& buzzMemory)
{
    buzzMemory.aero.reset();
}

void Aero::Update(BuzzMemory& buzzMemory, Entity& missile)
{
    // TODO: Parabolic Drag Polar
    buzzMemory.aero.Cl = Clao + Cla*buzzMemory.aero.alpha;
    buzzMemory.aero.Cd = Cdo + k*std::pow(buzzMemory.aero.Cl - Clo, 2);
}