#include <iostream>

#include "world.hxx"

int main() {
    std::shared_ptr<ECS::World> world(new ECS::World());

    // Setup systems (TODO)

    // Setup entities
    std::shared_ptr<ECS::Entity> player(new ECS::Entity());
    std::shared_ptr<ECS::Entity> map(new ECS::Entity());
    std::shared_ptr<ECS::Entity> loader(new ECS::Entity());

    world->addEntity(player);
    world->addEntity(map);
    world->addEntity(loader);

    // Begin!
    world->start();

    while (world->isRunning()) {
        world->run();
    }

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}