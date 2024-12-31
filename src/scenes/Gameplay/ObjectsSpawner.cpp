#include "ObjectsSpawner.h"

#include <raymath.h>

ObjectsSpawner::ObjectsSpawner(): projectilePool(INITIAL_PROJECTILE_POOL_SIZE), asteroidPool(INITIAL_PROJECTILE_POOL_SIZE)
{
}

void ObjectsSpawner::DrawPools() const
{
    projectilePool.DrawAllObjects();
    asteroidPool.DrawAllObjects();
}

void ObjectsSpawner::UpdatePools(float deltaTime)
{
    projectilePool.UpdateAllObjects(deltaTime);
    asteroidPool.UpdateAllObjects(deltaTime);
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

    constexpr float spawnDistance = 30.0f;
    Vector2 spawnPosition = Vector2Add(mainShip.GetPosition(), Vector2Scale(direction, spawnDistance));

    if (Projectile* projectile = projectilePool.GetAvailableObject())
    {
        projectile->Init(spawnPosition, direction, 250.0f);
    }
}