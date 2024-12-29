#include "MainMenu.h"
#include <iostream>

constexpr int BACKGROUND_FRAMES = 4;

MainMenu::MainMenu()
    : startButton("../graphics/start_button.png", {0.0f, 0.0f}, 0.5f),
      exitButton("../graphics/exit_button.png", {0.0f, 0.0f}, 0.5f),
      background({}), backgroundSourceRec({0}), backgroundDestRec({0}),
      animationFrameWidth(0), currentFrame(0), frameTime(0.2f), elapsedTime(0.0f)
{
}

void MainMenu::Init()
{
     int screenWidth = GetMonitorWidth(GetCurrentMonitor());
     int screenHeight = GetMonitorHeight(GetCurrentMonitor());

    background = LoadTexture("../graphics/background.png");

    animationFrameWidth = background.width / BACKGROUND_FRAMES;

    backgroundSourceRec = { 0.0f, 0.0f, (float)animationFrameWidth, (float)background.height };
    backgroundDestRec = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };

    startButton.SetPosition({(float)(screenWidth / 2 - 80), (float)(screenHeight / 2 - 100)});
    exitButton.SetPosition({(float)(screenWidth / 2 - 80), (float)(screenHeight / 2 + 50)});
}

void MainMenu::Update(Vector2 const mousePosition, bool const mousePressed, SceneManager &sceneManager)
{
    ButtonInteraction(mousePosition, mousePressed, sceneManager);
    BackgroundAnimation();
}

void MainMenu::Draw()
{
    DrawTexturePro(background, backgroundSourceRec, backgroundDestRec, {0.0f, 0.0f}, 0.0f, WHITE);

    startButton.Draw();
    exitButton.Draw();
}

void MainMenu::Unload()
{
    UnloadTexture(background);
}

void MainMenu::ButtonInteraction(Vector2 const mousePosition, bool const mousePressed, SceneManager &sceneManager)
{
    if (startButton.IsPressed(mousePosition, mousePressed))
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        sceneManager.SetCurrentScene(SceneType::GAME);
    }

    if (exitButton.IsPressed(mousePosition, mousePressed))
    {
        sceneManager.Exit();
    }
}

void MainMenu::BackgroundAnimation()
{
    elapsedTime += GetFrameTime();

    if (elapsedTime >= frameTime)
    {
        elapsedTime = 0.0f;
        currentFrame++;

        if (currentFrame >= BACKGROUND_FRAMES)
        {
            currentFrame = 0;
        }

        backgroundSourceRec.x = (float)(currentFrame * animationFrameWidth);
    }
}