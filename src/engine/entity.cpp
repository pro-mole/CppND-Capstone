// Entity Implementation
#include "entity.hxx"

int ECS::Entity::last_id = 0;

// Instantiate an Entity
ECS::Entity::Entity(ECS::World* world)
    : world(std::shared_ptr<ECS::World>(world)), id(++ECS::Entity::last_id) {}

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