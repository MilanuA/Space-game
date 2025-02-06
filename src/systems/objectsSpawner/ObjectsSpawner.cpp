#include "ObjectsSpawner.h"
#include <iostream>
#include <raymath.h>
#include "../debug/DebugGame.h"

ObjectsSpawner::ObjectsSpawner(ScoreManager &scoreManager, GameStateManager &gameStateManager): projectilePool(INITIAL_PROJECTILE_POOL_SIZE),
                                                            asteroidPool(INITIAL_PROJECTILE_POOL_SIZE), scoreManager(scoreManager), gameStateManager(gameStateManager)
{
    std::random_device rd;
    randomEngine = std::mt19937(rd());
}

void ObjectsSpawner::Draw() const
{
    projectilePool.DrawAllObjects();
    asteroidPool.DrawAllObjects();

    if (DebugGame::GetInstance().IsDebugEnabled())
        ShowPooledObjectsCount();
}

void ObjectsSpawner::Update(float deltaTime)
{
    projectilePool.UpdateAllObjects(deltaTime);
    asteroidPool.UpdateAllObjects(deltaTime);

    timeSinceLastSpawn += deltaTime;

    if (timeSinceLastSpawn >= ASTEROID_SPAWN_INTERVAL)
    {
        SpawnAsteroid();
        timeSinceLastSpawn = 0.0f;
    }
}

void ObjectsSpawner::SpawnProjectile(Vector2 mousePosition, MainShip &mainShip)
{
    if (mainShip.IsMovingFast()) return;

    Vector2 direction = Vector2Subtract(mousePosition, mainShip.GetPosition());
    float length = Vector2Length(direction);

    if (length > 0.0f)
    {
        direction = Vector2Normalize(direction);
    }

    Vector2 spawnPosition = Vector2Add(mainShip.GetPosition(), Vector2Scale(direction, PROJECTILE_SPAWN_DISTANCE));

    if (Projectile* projectile = projectilePool.GetAvailableObject())
    {
        projectile->Init(spawnPosition, direction);
    }
}

void ObjectsSpawner::SpawnAsteroid()
{
    if (Asteroid* asteroid = asteroidPool.GetAvailableObject())
    {
        std::uniform_int_distribution<int> sideDist(0, 3);
        int side = sideDist(randomEngine);

        Vector2 spawnPosition = {};
        Vector2 direction = {};

        std::uniform_int_distribution<int> xDist(0, GetScreenWidth());
        std::uniform_int_distribution<int> yDist(0, GetScreenHeight());

        switch (side)
        {
            case 0: // Left
                spawnPosition = { 0.0f, static_cast<float>(yDist(randomEngine)) };
            direction = { 1.0f, 0.0f };
            break;
            case 1: // Right
                spawnPosition = { static_cast<float>(GetScreenWidth()), static_cast<float>(yDist(randomEngine)) };
            direction = { -1.0f, 0.0f };
            break;
            case 2: // Top
                spawnPosition = { static_cast<float>(xDist(randomEngine)), 0.0f };
            direction = { 0.0f, 1.0f };
            break;
            case 3: // Bottom
                spawnPosition = { static_cast<float>(xDist(randomEngine)), static_cast<float>(GetScreenHeight()) };
            direction = { 0.0f, -1.0f };
            break;
            default:
                break;
        }

        asteroid->Init(spawnPosition, Vector2Normalize(direction), scoreManager, gameStateManager);
    }
}

void ObjectsSpawner::ShowPooledObjectsCount() const
{
    const int fontSize = 30;
    const int padding = 10;
    const int startX = 10;
    int startY = 150;

    DrawText(TextFormat("Projectiles: %d", projectilePool.GetActiveObjectCount()), startX, startY, fontSize, WHITE);
    startY += fontSize + padding;
    DrawText(TextFormat("Asteroids: %d", asteroidPool.GetActiveObjectCount()), startX, startY, fontSize, WHITE);
}
