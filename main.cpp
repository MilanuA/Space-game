#include "raylib.h"
#include "src/scenes/DeathScene.h"

#include "src/scenes/GameplayScene.h"
#include "src/scenes/MainMenuScene.h"
#include "src/scenes/SceneManager.h"

constexpr int FPS = 60;

void InitGame();
void DrawExitPrompt();
void CloseGame();

void UpdateGameLoop(bool &exitWindowRequested, SceneManager &sceneManager);
void DrawGameLoop(bool const exitWindowRequested, const SceneManager &sceneManager);

int main(void)
{
    InitGame();

    bool exitWindowRequested = false;
    bool exitWindow = false;

    SceneManager sceneManager;
    sceneManager.RegisterScene(SceneType::MAIN_MENU, std::make_unique<MainMenuScene>());
    sceneManager.RegisterScene(SceneType::GAME, std::make_unique<GameplayScene>());
    sceneManager.RegisterScene(SceneType::DEATH, std::make_unique<DeathScene>());

    sceneManager.SetCurrentScene(SceneType::DEATH);

    while (!exitWindow)
    {
        if (WindowShouldClose() || sceneManager.ShouldExit()) exitWindowRequested = true;

        if (exitWindowRequested)
        {
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }

        if (!exitWindowRequested)
            UpdateGameLoop(exitWindowRequested, sceneManager);

        DrawGameLoop(exitWindowRequested, sceneManager);
    }

    CloseGame();

    return 0;
}

void InitGame()
{
    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TOPMOST | FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 450, "Asteroids Clone");
  //  ToggleBorderlessWindowed();
    SetTargetFPS(FPS);
    InitAudioDevice();
}

void UpdateGameLoop(bool &exitWindowRequested, SceneManager &sceneManager)
{
    Vector2 mousePosition = GetMousePosition();
    bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    sceneManager.Update(mousePosition, mousePressed);

    if (exitWindowRequested)
    {
        if (IsKeyPressed(KEY_Y)) sceneManager.Exit();
        else if (IsKeyPressed(KEY_N) ) exitWindowRequested = false;
    }
}

void DrawGameLoop(bool const exitWindowRequested, const SceneManager &sceneManager)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    sceneManager.Draw();

    if (exitWindowRequested)
    {
        DrawExitPrompt();
    }

    EndDrawing();
}

void DrawExitPrompt()
{
    const char *exitText = "Are you sure you want to exit the game? [Y/N]";
    int exitPromptWidth = MeasureText(exitText, 40) + 50;
    int exitPromptHeight = 200;
    int exitPromptX = (GetScreenWidth() - exitPromptWidth) / 2;
    int exitPromptY = (GetScreenHeight() - exitPromptHeight) / 2;

    DrawRectangle(exitPromptX, exitPromptY, exitPromptWidth, exitPromptHeight, BLACK);

    int textX = exitPromptX + (exitPromptWidth - MeasureText(exitText, 40)) / 2;
    int textY = exitPromptY + (exitPromptHeight - 40) / 2;

    DrawText(exitText, textX, textY, 40, WHITE);
}

void CloseGame()
{
    CloseWindow();
    CloseAudioDevice();
}