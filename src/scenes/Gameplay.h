#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <vector>

#include "Scene.h"
#include "../ship/MainShip.h"
#include "../ui/score/ScoreManager.h"

class Projectile;

class Gameplay : public Scene
{
    ScoreManager scoreManager;
    MainShip mainShip;
    std::vector<Projectile> projectiles;

public:
    Gameplay();
    void Init() override;
    void Update(Vector2 mousePosition, bool wasLeftMousePressed, SceneManager &sceneManager) override;
    void Draw() override;
    void Unload() override;

    ~Gameplay() override;
};



#endif //GAMEPLAY_H
