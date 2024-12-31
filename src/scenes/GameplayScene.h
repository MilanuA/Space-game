#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Scene.h"
#include "../inGameObjects/Asteroid.h"
#include "../objectPooling/ObjectPool.h"
#include "../ship/MainShip.h"
#include "../ship/Projectile.h"
#include "../ui/score/ScoreManager.h"

constexpr size_t INITIAL_PROJECTILE_POOL_SIZE = 20;
constexpr size_t INITIAL_ASTEROID_POOL_SIZE = 20;

class GameplayScene : public Scene
{
    ScoreManager scoreManager;
    MainShip mainShip;
    Music music;
    ObjectPool<Projectile> projectilePool;
    ObjectPool<Asteroid> asteroidPool;

    void SpawnProjectile(Vector2 mousePosition);
    void UpdateProjectiles();
public:
    GameplayScene();
    void Init() override;
    void Update(Vector2 mousePosition, bool wasLeftMousePressed, SceneManager &sceneManager) override;
    void Draw() override;
    void Unload() override;

    ~GameplayScene() override;
};



#endif //GAMEPLAY_H
