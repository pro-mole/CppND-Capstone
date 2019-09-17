namespace ECS {
    class System;
}

#ifndef SYSTEM_H
#define SYSTEM_H

#include <list>

#include "component.hxx"
#include "entity.hxx"
#include "world.hxx"

namespace ECS {

    class System {
    public:
        System();

        // Fetch all of the required components in the target entity
        virtual std::list<std::shared_ptr<Component>> getComponents(
            Entity& entity) = 0;

        // Run logic on a particular entity
        virtual void runOnEntity(Entity& entity) = 0;

        // Run logic on every entity in the world that may be affected by this
        // system
        void runOnWorld(World* world);

    private:
    };

}  // namespace ECS

#endif