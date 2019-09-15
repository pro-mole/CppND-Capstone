namespace ECS {
    class Component;
}

#ifndef COMPONENT_H
#define COMPONENT_H

#include <condition_variable>
#include <list>
#include <mutex>

#include "entity.hxx"

namespace ECS {

    class Component {
    public:
        bool lock();
        bool unlock();

    private:
        Entity* entity;

        bool locked;
        std::mutex _lock;
        std::condition_variable _condition;
    };
}  // namespace ECS

#endif