// System Implementation
#include "system.hxx"

// Instantiate a new System
ECS::System::System(ECS::World* world)
    : world(std::shared_ptr<ECS::World>(world)) {}

void ECS::System::runOnWorld() {
    // For each entity in the world:
    // - Fetch the required components
    // - Lock the components before use
    // - Run logic upon said entity
    // - Unlock the components
}
