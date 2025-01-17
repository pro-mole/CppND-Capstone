# CPPND: Capstone Rogue-Lite

It this project, I'll program a rudimentary game engine that will be used to a rogue-lite, game, that is, a game that is inspired and share some gameplay and thematic characteristics with the classic game *Rogue*. It is essentially a turn-based dungeon crawling game, in which one player character moves through a dungeon in turns, after which every other creature in this same dungeon will also move.

The game engine itself will be based on the ECS architecture (*Entity-Component-System*), a data-driven game programming pattern that defines its game world as composed of Entities, which contain any number of Components, which are acted upon by independent Systems. The specifics of the ECS architecture implemented in this work is described below, as well as which entities, components and systems the game itself implement.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

*TBD - add SDL dependencies for drawing*

## Easy Build-and-Run Instructions

1. Clone this repo.
2. Run `./run.sh`

Alternatively:

1. Clone this repo.
2. Run `./make.sh`
3. Run `./RogueLite`

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./RogueLite`.

## Rubrics Addressed

The following criteria have been or will be addressed in the development of this project:

### Loops, Functions, I/O

- [ ] The project reads data from a file and process the data, or the program writes data to a file.
- [ ] The project accepts user input and processes the input.

### Object Oriented Programming

- [ ] Derived class functions override virtual base class functions.
- [x] Templates generalize functions in the project.
    - *src/engine/entity.cpp:18*

### Memory Management

- [x] The project makes use of references in function declarations.
    - *engine/world.hxx:29*, *engine/world.hxx:32*, *engine/entity.hxx:21*
- [x] The project uses smart pointers instead of raw pointers.

### Concurrency

- [x] The project uses multithreading.
    - *src/engine/world.cpp:89-96*
- [x] A mutex or lock is used in the project.
    - *src/engine/system.cpp:12-24*

*TODO: EVERYTHING below*

# Project Architecture

## ECS Characterstics

### Entity Types

### Component Types

### System Types

## The Rogue Engine

### Entities

### Components

### Systems

# Game Manual

## How to Play

## Objective