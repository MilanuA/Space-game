#ifndef OBJECTSSPAWNER_H
#define OBJECTSSPAWNER_H

#include "../../inGameObjects/Asteroid.h"
#include "../../objectPooling/ObjectPool.h"
#include "../../ship/MainShip.h"
#include "../../ship/Projectile.h"

constexpr size_t INITIAL_PROJECTILE_POOL_SIZE = 20;
constexpr size_t INITIAL_ASTEROID_POOL_SIZE = 20;
constexpr int SPAWN_DISTANCE = 30;

class ObjectsSpawner
{
    ObjectPool<Projectile> projectilePool;
    ObjectPool<Asteroid> asteroidPool;

    void SpawnAsteroid();

public:
    ObjectsSpawner();
    void Draw() const;
    void Update(float deltaTime);

    void SpawnProjectile(Vector2 mousePosition, MainShip &mainShip);
};



#endif //OBJECTSSPAWNER_H
