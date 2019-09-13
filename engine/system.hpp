#pragma once

#include <list>

#include "Component"
#include "Entity"
#include "World"

namespace ECS {

    template <class... C : Component>
    class System {
    public:
        void runOnEntity(Entity& entity) = 0;
        void runOnWorld();

    private:
        World* world;
    }

}  // namespace ECS