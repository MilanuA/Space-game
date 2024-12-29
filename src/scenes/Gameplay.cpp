#include "Gameplay.h"

#include <raymath.h>

#include "../ship/Projectile.h"


Gameplay::Gameplay()
{
}

void Gameplay::Init()
{
    mainShip.Init();
}

void Gameplay::Update(Vector2 const mousePosition, bool const wasLeftMousePressed, SceneManager &sceneManager)
{
    scoreManager.UpdateScorePerSecond();
    mainShip.UpdatePosition(mousePosition);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 direction = Vector2Subtract(mousePosition, mainShip.GetPosition());
        float length = Vector2Length(direction);

        if (length > 0.0f)
        {
            direction = Vector2Normalize(direction);
        }

        Projectile projectile(mainShip.GetPosition(), direction, 250.0f);
        projectiles.push_back(std::move(projectile));
    }

    const float deltaTime = GetFrameTime();

    for (auto &projectile : projectiles)
    {
        projectile.UpdateProjectile(deltaTime);
    }

    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
                                     [](const Projectile &p) { return !p.IsActive(); }),
                      projectiles.end());
}

void Gameplay::Draw()
{
    scoreManager.Draw();
    mainShip.DrawShip();

    for (const auto &projectile : projectiles)
    {
        projectile.DrawProjectile();
    }
}

void Gameplay::Unload()
{
}

Gameplay::~Gameplay()
{
}

