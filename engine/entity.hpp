#pragma once

#include <list>

#include "Component"
#include "World"

namespace ECS {
    enum EntityState { STOPPED, STARTED, PAUSED, DEAD };

    class Entity {
    public:
        template <class C : Component>
        void addComponent();
        template <class C : Component>
        C getComponent();

    private:
        World *world;
        std::list<Component> components;
        EntityState status;
    }
}  // namespace ECS