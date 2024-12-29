#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Scene.h"
#include "../ship/MainShip.h"
#include "../ui/score/ScoreManager.h"


class Gameplay : public Scene
{
    ScoreManager scoreManager;
    MainShip mainShip;
public:
    Gameplay();
    void Init() override;
    void Update(Vector2 mousePosition, bool mousePressed, SceneManager &sceneManager) override;
    void Draw() override;
    void Unload() override;

    ~Gameplay() override;
};



#endif //GAMEPLAY_H
