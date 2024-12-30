#include "Gameplay.h"

#include <raymath.h>

#include "../ship/Projectile.h"

Gameplay::Gameplay() : music(), projectilePool(INITIAL_POOL_SIZE)
{
}

void Gameplay::Init()
{
    mainShip.Init();

    music = LoadMusicStream("../resources/audio/spaceMusic.mp3");
    PlayMusicStream(music);
}

void Gameplay::Update(Vector2 const mousePosition, bool const wasLeftMousePressed, SceneManager &sceneManager)
{
    UpdateMusicStream(music);

    scoreManager.UpdateScorePerSecond();
    mainShip.UpdatePosition(mousePosition);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        SpawnProjectile(mousePosition);
    }

    UpdateProjectiles();
}

void Gameplay::Draw()
{
    scoreManager.Draw();
    mainShip.DrawShip();

    projectilePool.DrawAllObjects();
}

void Gameplay::Unload()
{
    UnloadMusicStream(music);
}

void Gameplay::UpdateProjectiles()
{
    const float deltaTime = GetFrameTime();

    projectilePool.UpdateAllObjects(deltaTime);
}

void Gameplay::SpawnProjectile(Vector2 mousePosition)
{
    Vector2 direction = Vector2Subtract(mousePosition, mainShip.GetPosition());
    float length = Vector2Length(direction);

    if (length > 0.0f)
    {
        direction = Vector2Normalize(direction);
    }

    if (Projectile* projectile = projectilePool.GetAvailableObject())
    {
        projectile->Init(mainShip.GetPosition(), direction, 250.0f);
    }
}

Gameplay::~Gameplay()
{
}

