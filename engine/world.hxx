namespace ECS {
    class World;
}

#ifndef WORLD_H
#define WORLD_H

#include <list>
#include <memory>

#include <SDL2/SDL.h>

#include "component.hxx"
#include "entity.hxx"
#include "system.hxx"

// Custom deleter for SDL_Window type
class WindowDeleter {
public:
    void operator()(SDL_Window* window) { SDL_DestroyWindow(window); }
};

namespace ECS {
    class World {
    public:
        World();

        // Organization functions
        std::shared_ptr<Entity> createEntity();
        template <class S>
        std::shared_ptr<S> createSystem();

        template <class S>
        std::shared_ptr<S> getSystem();

        std::list<std::shared_ptr<Entity>>& getEntities();

        bool isRunning();

        // Processing functions
        void start();
        void run();
        void end();

    private:
        // The length of the latest tick (for processing) (in milliseconds)
        int current_tick;
        // The moment this world was last updated (in milliseconds)
        int last_update;
        // Is the game running?
        bool running;

        // Input queue

        // List of Systems in the World
        std::list<std::shared_ptr<System>> systems;
        // List of Entities in the World
        std::list<std::shared_ptr<Entity>> entities;

        // SDL Stuff
        // Game Window
        std::unique_ptr<SDL_Window, WindowDeleter> window;
        // Base canvas (for rendering)
        std::unique_ptr<SDL_Surface> canvas;
    };

}  // namespace ECS

#endif