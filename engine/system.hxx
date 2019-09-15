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
        System(World*);

        // Fetch all of the required components in the target entity
        virtual std::list<Entity&> getComponents(Entity& entity) = 0;

        // Run logic on a particular entity
        virtual void runOnEntity(Entity& entity) = 0;

        // Run logic on every entity in the world that may be affected by this
        // system
        void runOnWorld();

    private:
        std::shared_ptr<ECS::World> world;
    };

}  // namespace ECS

#endif