#include "buzzsim.h"

void Buzzsim::init()
{
    aero = std::make_unique<Aero>();
    airframe = std::make_unique<Airframe>();
    atmos = std::make_unique<Atmos>();
    autopilot = std::make_unique<Autopilot>();
    eom = std::make_unique<EOM>();
    guidance = std::make_unique<Guidance>();
    prop = std::make_unique<Prop>();
    
    if(debug_)
        std::cout << "BUZZSIM Initiated..." << std::endl;
}

int main()
{
    std::unique_ptr<Buzzsim> buzzsim = std::make_unique<Buzzsim>();
    
    return 0;
}