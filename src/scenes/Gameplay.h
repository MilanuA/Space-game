#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Scene.h"
#include "../objectPooling/ObjectPool.h"
#include "../ship/MainShip.h"
#include "../ship/Projectile.h"
#include "../ui/score/ScoreManager.h"

constexpr size_t INITIAL_POOL_SIZE = 20;

class Gameplay : public Scene
{
    ScoreManager scoreManager;
    MainShip mainShip;
    Music music;
    ObjectPool<Projectile> projectilePool;

    void SpawnProjectile(Vector2 mousePosition);
    void UpdateProjectiles();
public:
    Gameplay();
    void Init() override;
    void Update(Vector2 mousePosition, bool wasLeftMousePressed, SceneManager &sceneManager) override;
    void Draw() override;
    void Unload() override;

    ~Gameplay() override;
};



#endif //GAMEPLAY_H
