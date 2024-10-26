#include <iostream>
#include <memory>
#include <string>

#include "aero.h"
#include "actuator.h"
#include "atmos.h"
#include "autopilot.h"
#include "eom.h"
#include "guidance.h"
#include "prop.h"

class Buzzsim
{
    public:
        Buzzsim()
        {
            Init();
        }
        void Init();
        bool debug_ = true;

    private:
        std::unique_ptr<Aero>      aero;
        std::unique_ptr<Actuator>  actuator;
        std::unique_ptr<Atmos>     atmos;
        std::unique_ptr<Autopilot> autopilot;
        std::unique_ptr<EOM>       eom;
        std::unique_ptr<Guidance>  guidance;
        std::unique_ptr<Prop>      prop;

        std::string name_ = "NONE";
};