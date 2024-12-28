#include "raylib.h"
#include <iostream>

#include "src/scenes/MainMenu.h"
#include "src/scenes/SceneManager.h"

int main(void)
{
    const int fps = 60;

    InitWindow(800, 450, "Simple game");
    SetTargetFPS(fps);
    ToggleFullscreen();

    SceneManager sceneManager;
    sceneManager.RegisterScene(SceneType::MAIN_MENU, std::make_unique<MainMenu>());

    sceneManager.SetCurrentScene(SceneType::MAIN_MENU);

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
