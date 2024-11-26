#include "buzz_memory.h"
#include "entity.h"


class Prop
{
    public:
        void Init(BuzzMemory& buzzMemory);
        void Update(BuzzMemory& buzzMemory, Entity& missile);

        // TODO: configuration for exhaust nozzle area
        double Ae = 0.0;
    private:
};