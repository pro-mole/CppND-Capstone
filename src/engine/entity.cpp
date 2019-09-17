// Entity Implementation
#include "entity.hxx"

#include <iostream>

int ECS::Entity::last_id = 0;

// Instantiate an Entity
ECS::Entity::Entity() : id(++ECS::Entity::last_id) {}

// Adds a component of given type to the Entity
std::shared_ptr<ECS::Component> ECS::Entity::addComponent(ECS::Component& C) {
    std::shared_ptr<Component> component(&C);
    this->components.push_back(component);
    return component;
}

std::shared_ptr<ECS::Component> ECS::Entity::addComponent(
    std::shared_ptr<Component> component) {
    this->components.push_back(component);
    return component;
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
