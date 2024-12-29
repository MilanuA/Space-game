#include "raylib.h"
#include <iostream>

#include "src/scenes/Gameplay.h"
#include "src/scenes/MainMenu.h"
#include "src/scenes/SceneManager.h"

int main(void)
{
    const int fps = 60;

    // Init window
    InitWindow(800, 450, "Asteroids Clone");
    SetTargetFPS(fps);
    ToggleFullscreen();

    // Create the scene manager
    SceneManager sceneManager;

    // Register each scene
    sceneManager.RegisterScene(SceneType::MAIN_MENU, std::make_unique<MainMenu>());
    sceneManager.RegisterScene(SceneType::GAME, std::make_unique<Gameplay>());

    // Set the current scene
    sceneManager.SetCurrentScene(SceneType::MAIN_MENU);

    // Main game loop
    while (!WindowShouldClose() && !sceneManager.ShouldExit())
    {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        sceneManager.Update(mousePosition, mousePressed);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        sceneManager.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
