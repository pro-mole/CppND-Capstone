// Game World Implementation
#include <iostream>
#include <string>
#include <thread>
#include <typeinfo>

#include "world.hxx"

// Instantiate a World
ECS::World::World() : last_update(0), current_tick(0), running(false) {
    // Nothing to do for now
}

// Create an Entity in the World
std::shared_ptr<ECS::Entity> ECS::World::createEntity() {
    std::shared_ptr<ECS::Entity> newEntity(new ECS::Entity());

    this->entities.push_back(newEntity);
    return newEntity;
}

// Create a System in the World
template <class S>
std::shared_ptr<S> ECS::World::createSystem() {
    static_assert(std::is_base_of<ECS::System, S>::value,
                  "Attempt to create System of non-System class!");

    std::shared_ptr<S> newSystem(new S());

    this->systems.push_back(newSystem);
    return newSystem;
}

// Return the list of entities in this world
std::list<std::shared_ptr<ECS::Entity>>& ECS::World::getEntities() {
    return this->entities;
}

// Is the world running?
bool ECS::World::isRunning() { return this->running; }

// Starts the game (and all the systems within)
void ECS::World::start() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized!" << std::endl;
        return;
    }

    // Create the window
    this->window = std::unique_ptr<SDL_Window, WindowDeleter>(
        SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN));
    if (this->window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        return;
    }

    // Get window surface
    this->canvas =
        std::unique_ptr<SDL_Surface>(SDL_GetWindowSurface(this->window.get()));

    this->running = true;
    this->last_update = SDL_GetTicks();
}

// Process one single tick for every system in the world
void ECS::World::run() {
    // Handle events
    SDL_Event ev;
    while (SDL_PollEvent(&ev) != 0) {
        // Close button and/or interrupt
        if (ev.type == SDL_QUIT) {
            this->end();
            return;
        }
    }

    std::list<std::thread> system_threads;
    // Run every system in a separate thread
    for (auto system : this->systems) {
        system_threads.emplace_back(
            std::thread(&System::runOnWorld, system, this));
    }

    for (auto& thread : system_threads) {
        thread.join();
    }

    // Update the last update time
    this->current_tick = SDL_GetTicks() - this->last_update;
    this->last_update = SDL_GetTicks();

    SDL_UpdateWindowSurface(this->window.get());
}

// Ends the game (and stops everything within)
void ECS::World::end() {
    SDL_FreeSurface(this->canvas.get());

    SDL_DestroyWindow(this->window.get());

    SDL_Quit();

    this->running = false;
}