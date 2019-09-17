// Entity Implementation
#include "entity.hxx"

#include <iostream>

int ECS::Entity::last_id = 0;

// Instantiate an Entity
ECS::Entity::Entity() : id(++ECS::Entity::last_id) {}

// Adds a component of given type to the Entity
template <class C>
ECS::Component& ECS::Entity::addComponent() {
    static_assert(std::is_base_of<ECS::Component, C>::value,
                  "Attempt to create Component of non-Component class!");

    C newComponent;
    this->components.push_back(newComponent);
    return newComponent;
}

// Fetch a component of given type from the Entity (or null, if none was found)
template <class C>
std::shared_ptr<C> ECS::Entity::getComponent() {
    std::shared_ptr<C> pointer;

    for (auto component : this->components) {
        pointer = dynamic_cast<C>(component);
        if (pointer != nullptr) return pointer;
    }

    return std::shared_ptr<C>(nullptr);
}

// Locks the entity, if available
bool ECS::Entity::lock() {
    std::unique_lock<std::mutex> entityLock(this->_lock);
    this->_condition.wait(entityLock, [this]() { return this->locked; });
    this->locked = true;
}

// Unlocks the entity
bool ECS::Entity::unlock() { this->locked = false; }
