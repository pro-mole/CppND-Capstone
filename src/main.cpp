#include <iostream>

#include "world.hxx"

int main() {
    ECS::World* world = new ECS::World();

    world->start();

    while (world->isRunning()) {
        world->run();
    }

    delete world;

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}