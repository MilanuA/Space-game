#include "MainMenuScene.h"

constexpr int BACKGROUND_FRAMES = 4;

MainMenuScene::MainMenuScene()
    : startButton("../resources/ui/buttons/play_button.png", {0.0f, 0.0f}, 8.f),
      exitButton("../resources/ui/buttons/exit_button.png", {0.0f, 0.0f}, 8.),
      background({}), backgroundSourceRec({0}), backgroundDestRec({0}), sceneManager(sceneManager)
{
}

void MainMenuScene::Init(SceneManager &sceneManager)
{
    this->sceneManager = &sceneManager;

    int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    int screenHeight = GetMonitorHeight(GetCurrentMonitor());

    background = LoadTexture("../resources/background.png");

    backgroundSourceRec = {0.0f, 0.0f, (float)background.width , (float)background.height};
    backgroundDestRec = {0.0f, 0.0f, (float)screenWidth, (float)screenHeight};

    Vector2 startBtnSize = startButton.Size();
    Vector2 exitBtnSize = exitButton.Size();

    startButton.SetPosition({(float)(screenWidth / 2  - startBtnSize.x / 2 ), (float)(screenHeight / 2 - 100)});
    exitButton.SetPosition({(float)(screenWidth / 2 - exitBtnSize.x / 2), (float)(screenHeight / 2 + 50)});
}

void MainMenuScene::Update(Vector2 const mousePosition, bool const mousePressed)
{
    ButtonInteraction(mousePosition, mousePressed);
}

void MainMenuScene::Draw()
{
    DrawTexturePro(background, backgroundSourceRec, backgroundDestRec, {0.0f, 0.0f}, 0.0f, WHITE);

    startButton.Draw();
    exitButton.Draw();
}

void MainMenuScene::Unload()
{
    UnloadTexture(background);
}

void MainMenuScene::ButtonInteraction(Vector2 const mousePosition, bool const mousePressed)
{
    if (startButton.IsPressed(mousePosition, mousePressed))
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        sceneManager->SetCurrentScene(SceneType::GAME);
    }

    if (exitButton.IsPressed(mousePosition, mousePressed))
    {
        sceneManager->Exit();
    }
}
