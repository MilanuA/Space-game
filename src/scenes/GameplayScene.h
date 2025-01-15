#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Scene.h"
#include "../objects/ship/MainShip.h"
#include "../systems/objectsSpawner/ObjectsSpawner.h"
#include "../ui/healthBar/HealthBar.h"
#include "../ui/score/ScoreManager.h"

class GameplayScene : public Scene
{
    ScoreManager scoreManager;
    ObjectsSpawner objectsSpawner;
    MainShip mainShip;
    HealthBar healthBar;
    Music music;

    void ShowFPS();

public:
    GameplayScene();
    void Init() override;
    void Update(Vector2 mousePosition, bool wasLeftMousePressed, SceneManager &sceneManager) override;
    void Draw() override;
    void Unload() override;

    ~GameplayScene() override;
};



#endif //GAMEPLAY_H
