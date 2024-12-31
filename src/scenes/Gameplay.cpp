#include "Gameplay.h"

#include <raymath.h>

#include "../ship/Projectile.h"

Gameplay::Gameplay() : music(), projectilePool(INITIAL_PROJECTILE_POOL_SIZE), asteroidPool(INITIAL_ASTEROID_POOL_SIZE)
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
    asteroidPool.DrawAllObjects();
}

void Gameplay::Unload()
{
    UnloadMusicStream(music);
}

void Gameplay::UpdateProjectiles()
{
    const float deltaTime = GetFrameTime();

    projectilePool.UpdateAllObjects(deltaTime);
    asteroidPool.UpdateAllObjects(deltaTime);
}

void Gameplay::SpawnProjectile(Vector2 mousePosition)
{
    if (mainShip.IsMovingFast()) return;

    Vector2 direction = Vector2Subtract(mousePosition, mainShip.GetPosition());
    float length = Vector2Length(direction);

    if (length > 0.0f)
    {
        direction = Vector2Normalize(direction);
    }

    constexpr float spawnDistance = 30.0f;
    Vector2 spawnPosition = Vector2Add(mainShip.GetPosition(), Vector2Scale(direction, spawnDistance));

    if (Projectile* projectile = projectilePool.GetAvailableObject())
    {
        projectile->Init(spawnPosition, direction, 250.0f);
    }
}


Gameplay::~Gameplay()
{
}

