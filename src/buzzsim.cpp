#include "buzzsim.h"

void Buzzsim::Init()
{
    aero_ = std::make_unique<Aero>();
    actuator_ = std::make_unique<Actuator>();
    atmos_ = std::make_unique<Atmos>();
    autopilot_ = std::make_unique<Autopilot>();
    eom_ = std::make_unique<EOM>();
    guidance_ = std::make_unique<Guidance>();
    prop_ = std::make_unique<Prop>();

    buzzMemory_ = std::make_unique<BuzzMemory>();
    missile_ = std::make_unique<Entity>();

    missile_->refArea = 0.049;
    missile_->refLength = 0.25;
    
    if(debug_)
        std::cout << "BUZZSIM Initiated..." << std::endl;
}

int main()
{
    // TODO: Initialize reference area and length
    std::unique_ptr<Buzzsim> buzzsim = std::make_unique<Buzzsim>();
    
    // Run update routines in a loop

    return 0;
}