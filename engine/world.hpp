#pragma once

#include <list>

#include "Component"
#include "Entity"
#include "System"

namespace ECS {

    class ECSEngine {
    public:
        Entity createEntity(...);
        template <class S : System>
        S createSystem(...);

    private:
        std::list<System*> systems;
        std::list<Entity*> entities;
    }

}  // namespace ECS