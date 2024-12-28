#include "raylib.h"
#include "src/ui/button/Button.h"
#include <iostream>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int fps = 60;

    InitWindow(screenWidth, screenHeight, "Simple game");
    SetTargetFPS(fps);

    // Load background
    Texture2D background = LoadTexture("../graphics/background.png");
    Rectangle backgroundSourceRec = { 0.0f, 0.0f, (float)background.width, (float)background.height };
    Rectangle backgroundDestRec = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };

    // Buttons with initial positions
    Button startButton{"../graphics/start_button.png", {screenWidth / 2 - 80, screenHeight / 2 - 100}, 0.65};
    Button exitButton{"../graphics/exit_button.png", {screenWidth / 2 - 80, screenHeight / 2 + 50}, 0.65};

    bool exit = false;

    while (!WindowShouldClose() && !exit)
    {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (IsKeyPressed(KEY_F11))
        {
            int display = GetCurrentMonitor();

            if (IsWindowFullscreen())
            {
                SetWindowSize(screenWidth, screenHeight);
                backgroundDestRec = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };
                startButton.SetPosition({screenWidth / 2 - 80, screenHeight / 2 - 100});
                exitButton.SetPosition({screenWidth / 2 - 80, screenHeight / 2 + 50});
            }
            else
            {
                SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
                backgroundDestRec = { 0.0f, 0.0f, (float)GetMonitorWidth(display), (float)GetMonitorHeight(display)};
                startButton.SetPosition({(float)GetMonitorWidth(display) / 2 - 80.0f, (float)GetMonitorHeight(display) / 2 - 100.0f});
                exitButton.SetPosition({(float)GetMonitorWidth(display) / 2 - 80.0f, (float)GetMonitorHeight(display) / 2 + 50.0f});
            }

            ToggleFullscreen();
        }


        if (startButton.IsPressed(mousePosition, mousePressed))
        {
            std::cout << "Start Button Pressed" << std::endl;
        }

        if (exitButton.IsPressed(mousePosition, mousePressed))
        {
            exit = true;
        }

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(background, backgroundSourceRec, backgroundDestRec, {0.0f, 0.0f}, 0.0f, WHITE);
        startButton.Draw();
        exitButton.Draw();
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}
