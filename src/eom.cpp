#include "eom.h"

void EOM::Init(std::unique_ptr<BuzzMemory> buzzMemory)
{
    buzzMemory->eom.reset();
}

void EOM::Update(std::unique_ptr<BuzzMemory> buzzMemory, std::unique_ptr<Entity> missile)
{
    double thrust = buzzMemory->prop.thrust;
    double dyn_pressure = buzzMemory->atmos.dyn_pressure;
    double alpha = buzzMemory->aero.alpha;
    double bank = buzzMemory->aero.bank;
    double mass = buzzMemory->prop.mass;
    double Cl = buzzMemory->aero.Cl;   
    double Cd = buzzMemory->aero.Cd;   

    // Velocity frame to Gravitational frame
    buzzMemory->eom.forces[0] = (thrust - dyn_pressure*missile->refArea*Cd)/mass;
    buzzMemory->eom.forces[1] = (sin(bank)*(thrust*sin(alpha) + dyn_pressure*missile->refArea*Cl))/mass;
    buzzMemory->eom.forces[2] = (-cos(bank)*(thrust*sin(alpha) + dyn_pressure*missile->refArea*Cl))/mass;
}