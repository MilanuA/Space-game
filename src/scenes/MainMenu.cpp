#include "MainMenu.h"

#include <iostream>

MainMenu::MainMenu()
    : startButton("../graphics/start_button.png", {0.0f, 0.0f}, 0.50f),
      exitButton("../graphics/exit_button.png", {0.0f, 0.0f}, 0.50f),
      background({}), backgroundSourceRec({0}), backgroundDestRec({0})
{
}

void MainMenu::Init()
{
    int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    int screenHeight = GetMonitorHeight(GetCurrentMonitor());

    background = LoadTexture("../graphics/background.png");
    backgroundSourceRec = { 0.0f, 0.0f, (float)background.width, (float)background.height };
    backgroundDestRec = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };

    startButton.SetPosition({(float)(screenWidth / 2 - 80), (float)(screenHeight / 2 - 100)});
    exitButton.SetPosition({(float)(screenWidth / 2 - 80), (float)(screenHeight / 2 + 50)});
}

void MainMenu::Update(Vector2 mousePosition, bool mousePressed, SceneManager &sceneManager)
{
    if (startButton.IsPressed(mousePosition, mousePressed))
    {
        std::cout << "Start Button Pressed" << std::endl;
    }

    if (exitButton.IsPressed(mousePosition, mousePressed))
    {
        sceneManager.Exit();
    }
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