#ifndef OBJECTSSPAWNER_H
#define OBJECTSSPAWNER_H

#include <random>
#include "../../objectPooling/ObjectPool.h"
#include "../../objects/asteroid/Asteroid.h"
#include "../../objects/projectile/Projectile.h"
#include "../../objects/ship/MainShip.h"
#include "../../ui/score/ScoreManager.h"

constexpr size_t INITIAL_PROJECTILE_POOL_SIZE = 20;
constexpr size_t INITIAL_ASTEROID_POOL_SIZE = 25;
constexpr int PROJECTILE_SPAWN_DISTANCE = 35;
constexpr float ASTEROID_SPAWN_INTERVAL = .5f;

class ObjectsSpawner
{
    ObjectPool<Projectile> projectilePool;
    ObjectPool<Asteroid> asteroidPool;

    void SpawnAsteroid();

    float timeSinceLastSpawn = 0.0f;
    std::mt19937 randomEngine;

    ScoreManager &scoreManager;

    void ShowPooledObjectsCount() const;
public:

    ObjectsSpawner(ScoreManager &scoreManager);

    void Init(ScoreManager &scoreManager) const;
    void Draw() const;
    void Update(float deltaTime);

    void SpawnProjectile(Vector2 mousePosition, MainShip &mainShip);
};



#endif //OBJECTSSPAWNER_H
