#include "buzz_memory.h"
#include "entity.h"
class Aero
{
    public:
        void Init(BuzzMemory& buzzMemory);
        void Update(BuzzMemory& buzzMemory, Entity& missile);

        // TODO: Temp aero variables, need aerodata and implement lookup table
        double Clo = 0.0;
        double Cdo = 0.0;
        double Cla = 0.0;
        double Clao = 0.0;
        double k = 0.0;

    private:
};