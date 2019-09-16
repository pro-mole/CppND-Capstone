// System Implementation
#include "system.hxx"

// Instantiate a new System
ECS::System::System(ECS::World* world)
    : world(std::shared_ptr<ECS::World>(world)) {}

void ECS::System::runOnWorld() {
    // For each entity in the world:
    for (auto entity : this->world->getEntities()) {
        // - Fetch the required components
        std::list<std::shared_ptr<ECS::Component>> components =
            this->getComponents(*entity);

        // - Lock the components before use
        entity->lock();
        for (auto component : components) {
            component->lock();
        }
        entity->unlock();

        // - Run logic upon said entity
        this->runOnEntity(*entity);

        // - Unlock the components
        for (auto component : components) {
            component->unlock();
        }
    }
}
