#include "Gameplay.h"



Gameplay::Gameplay()
{
}

void Gameplay::Init()
{
    mainShip.Init();
}

void Gameplay::Update(Vector2 mousePosition, bool mousePressed, SceneManager &sceneManager)
{
    scoreManager.UpdateScorePerSecond();
    mainShip.UpdatePosition(mousePosition);
}

void Gameplay::Draw()
{
    scoreManager.Draw();
    mainShip.DrawShip();
}

void Gameplay::Unload()
{
}

Gameplay::~Gameplay()
{
}

