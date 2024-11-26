#include "buzz_memory.h"
#include "entity.h"
#include <memory>


class Prop
{
    public:
        void Init(std::unique_ptr<BuzzMemory> buzzMemory);
        void Update(std::unique_ptr<BuzzMemory> buzzMemory, std::unique_ptr<Entity> missile);

        // TODO: configuration for exhaust nozzle area
        double Ae = 0.0;
    private:
};