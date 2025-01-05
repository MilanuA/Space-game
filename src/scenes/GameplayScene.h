#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Scene.h"
#include "../objects/ship/MainShip.h"
#include "../ui/score/ScoreManager.h"
#include "Gameplay/ObjectsSpawner.h"

class GameplayScene : public Scene
{
    ScoreManager scoreManager;
    ObjectsSpawner objectsSpawner;
    MainShip mainShip;
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
