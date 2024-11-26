#include "buzz_memory.h"
#include "entity.h"
#include <memory>

class Atmos
{
    public:
        void Init(std::unique_ptr<BuzzMemory> buzzMemory);
        void Update(std::unique_ptr<BuzzMemory> buzzMemory, std::unique_ptr<Entity> missile);

    private:
};