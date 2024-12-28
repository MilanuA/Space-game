#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int fps = 60;

    InitWindow(screenWidth, screenHeight, "Simple game");

    SetTargetFPS(fps);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F11))
        {
            int display = GetCurrentMonitor();
            
            if (IsWindowFullscreen())
            {
                SetWindowSize(screenWidth, screenHeight);
            }
            else
            {
                SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
            }

            ToggleFullscreen();
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Press Alt + Enter to Toggle full screen!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}