#pragma once

#include <condition_variable>
#include <list>
#include <mutex>

#include "Entity"

namespace ECS {

    class Component {
    public:
        bool lock();
        bool unlock();

    private:
        Entity* entity;

        bool locked;
        std::mutex lock;
        std::condtion_variable condition;
    }
}  // namespace ECS