#include "buzzsim.h"
#include <stdio.h>
#include <iostream>
#include <memory>

void Buzzsim::init()
{
    aero = std::make_unique<Aero>();
    airframe = std::make_unique<Airframe>();
    atmos = std::make_unique<Atmos>();
    autopilot = std::make_unique<Autopilot>();
    eom = std::make_unique<EOM>();
    guidance = std::make_unique<Guidance>();
    prop = std::make_unique<Prop>();
}

int main()
{
    printf("hey");
    return 0;
}