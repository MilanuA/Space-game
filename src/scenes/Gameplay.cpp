#include "Gameplay.h"



Gameplay::Gameplay() : score(0)
{
}

void Gameplay::Init()
{
    mainShip.Init();
}

void Gameplay::Update(Vector2 mousePosition, bool mousePressed, SceneManager &sceneManager)
{
    UpdateScorePerSecond();

    mainShip.UpdatePosition(mousePosition);
}

void Gameplay::Draw()
{
    const std::string scoreText = "Score: " + std::to_string(score);

    DrawText(scoreText.c_str(), 10, 10, 20, BLACK);

    mainShip.DrawShip();
}

void Gameplay::Unload()
{
}

Gameplay::~Gameplay()
{
}

void Gameplay::UpdateScorePerSecond()
{
    static float elapsedTime = 0.0f;
    elapsedTime += GetFrameTime();

    if (elapsedTime >= 1.0f)
    {
        score += scorePerSecond;
        elapsedTime = 0.0f;
    }
}
