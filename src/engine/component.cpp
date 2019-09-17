// Component Implementation

#include "component.hxx"

// Locks the component, if available
bool ECS::Component::lock() {
    std::unique_lock<std::mutex> componentLock(this->_lock);
    this->_condition.wait(componentLock, [this]() { return this->locked; });
    this->locked = true;
}

// Unlocks the component
bool ECS::Component::unlock() { this->locked = false; }