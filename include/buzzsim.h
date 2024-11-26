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
#include "entity.h"
#include "buzz_memory.h"

class Buzzsim
{
    public:
        Buzzsim()
        {
            Init();
        }
        void Init();
        void Update();
        bool debug_ = true;

        std::unique_ptr<Aero>       aero_;
        std::unique_ptr<Actuator>   actuator_;
        std::unique_ptr<Atmos>      atmos_;
        std::unique_ptr<Autopilot>  autopilot_;
        std::unique_ptr<EOM>        eom_;
        std::unique_ptr<Guidance>   guidance_;
        std::unique_ptr<Prop>       prop_;

        std::unique_ptr<BuzzMemory> buzzMemory_;
        std::unique_ptr<Entity>     missile_;

        std::string name_ = "NONE";

    private:
};