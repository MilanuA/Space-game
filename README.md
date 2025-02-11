# Space game

This project is a simple space-themed game built using C++ and the Raylib library. It features basic game mechanics such as player-controlled ships, projectiles, and asteroids.

**Disclaimer:** This project is still in development, and it is made for educational purposes only.

## Features

- **Main menu**: Navigate between different game scenes.
- **Gameplay**: Control the main ship, shoot projectiles, and avoid or destroy asteroids.
- **Scoring system**: Tracks and displays the player's score.
- **Health bar**: Displays the player's health.
- **Object pooling**: Handles the pooling of game objects.
- **Simple Gameobject system**: Ability to add and remove game objects and their components.
- **Simple Collision detection**: Detects collisions between game objects.
- **Simple Debug mode**: For debugging purposes. (Press F2 to toggle)
- **State machine**: Handles the game's state transitions.
- **Animation**: Handles the animation of game objects.
- **Console**: Dynamic in-game console showcasing logs.


## Project Structure

### 📂 src
- 📂 gameobject
  - 📂 components
- 📂 objects
  - 📂 asteroid
  - 📂 projectile
  - 📂 ship
- 📂 scenes
- 📂 systems
  - 📂 animation
  - 📂 collisionManager
  - 📂 debug
  - 📂 gameState
    - 📂 states
      - 📂 _baseInterface
  - 📂 health
  - 📂 objectPooling
  - 📂 objectsSpawner
- 📂 ui
  - 📂 button
  - 📂 healthBar
  - 📂 score
  - 📂 slider
  - 📂 console


## Dependencies

- [**Raylib**](https://github.com/raysan5/raylib): A simple and easy-to-use library to enjoy game programming.
- [**CMake**](https://cmake.org/): Used for managing the build process.

## Building the Project

1. Install CMake.
2. Clone the repository.
3. Run `cmake` to configure the project.
4. Build the project using your preferred build system.


## Credits
- Music: [Space](https://pixabay.com/music/upbeat-space-120280/)
- Assets: 
  - [Ship and asteroids](https://foozlecc.itch.io/)
  - [Buttons](https://slyfox-studios.itch.io/buttons-pack)
  - [Health Bar](https://fliflifly.itch.io/hearts-and-health-bar)
