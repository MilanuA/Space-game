#include "DeathScene.h"

DeathScene::DeathScene():
restartButton("../resources/ui/buttons/newgame_button.png", {0.0f, 0.0f}, 8.f),
menuButton("../resources/ui/buttons/menu_button.png", {0.0f, 0.0f}, 8.f)
{
}


void DeathScene::Init(SceneManager &sceneManager)
{
    this->scene_manager = &sceneManager;

    int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    int screenHeight = GetMonitorHeight(GetCurrentMonitor());

    Vector2 restartButtonSize = restartButton.Size();
    Vector2 menuButtonSize = menuButton.Size();

    restartButton.SetPosition({(float)(screenWidth / 2 - restartButtonSize.x / 2), (float)(screenHeight / 2 - 100)});
    menuButton.SetPosition({(float)(screenWidth / 2 - menuButtonSize.x / 2), (float)(screenHeight / 2 + 50)});
}

void DeathScene::Update(Vector2 mousePosition, bool mousePressed)
{
    ButtonInteraction(mousePosition, mousePressed);
}

void DeathScene::Draw()
{
    ClearBackground(BLACK);
    DrawText("You have died", GetScreenWidth() / 2 - MeasureText("You have died", 100) / 2, GetScreenHeight() / 2 - 400, 100, WHITE);

    menuButton.Draw();
    restartButton.Draw();
}

void DeathScene::Unload()
{
}

void DeathScene::ButtonInteraction(Vector2 mousePosition, bool mousePressed)
{
    if (menuButton.IsPressed(mousePosition, mousePressed))
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        scene_manager->SetCurrentScene(SceneType::MAIN_MENU);

    }

    if (restartButton.IsPressed(mousePosition, mousePressed))
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        scene_manager->SetCurrentScene(SceneType::GAME);
    }
}

