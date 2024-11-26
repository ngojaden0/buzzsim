#include "buzzsim.h"
#include <memory>

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

    // Set Initial Conditions here but will later use config file
    missile_->refArea = 0.049;
    missile_->refLength = 0.25;
    
    if(debug_)
        std::cout << "BUZZSIM Initiated..." << std::endl;
}

void Buzzsim::Update()
{
    atmos_->Update(std::move(buzzMemory_), std::move(missile_));
    aero_->Update(std::move(buzzMemory_), std::move(missile_));
    prop_->Update(std::move(buzzMemory_), std::move(missile_));
    eom_->Update(std::move(buzzMemory_), std::move(missile_));
    // guidance_->Update(std::move(buzzMemory_), std::move(missile_));
    // autopilot_->Update(std::move(buzzMemory_), std::move(missile_));
    // actuator_->Update(std::move(buzzMemory_), std::move(missile_));
}

int main()
{
    // TODO: Initialize reference area and length
    std::unique_ptr<Buzzsim> buzzsim = std::make_unique<Buzzsim>();
    
    // Run update routines in a loop

    return 0;
}