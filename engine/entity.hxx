namespace ECS {
    class Entity;
}

#ifndef ENTITY_H
#define ENTITY_H

#include <list>
#include <memory>

#include "component.hxx"
#include "world.hxx"

namespace ECS {
    enum EntityState { STOPPED, STARTED, PAUSED, DEAD };

    class Entity {
    public:
        Entity();

        Component& addComponent(Component&);
        Component& addComponent(std::shared_ptr<Component>);

        template <class C>
        std::shared_ptr<C> getComponent();

        bool lock();
        bool unlock();

    private:
        static int last_id;
        int id;

        std::list<Component> components;
        EntityState status;

        bool locked;
        std::mutex _lock;
        std::condition_variable _condition;
    };

}  // namespace ECS

#endif