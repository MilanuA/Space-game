#ifndef DEATHSCENE_H
#define DEATHSCENE_H
#include "Scene.h"


class DeathScene : public  Scene
{
public:
    DeathScene();

    void Init(SceneManager &sceneManager) override;
    void Update(Vector2 mousePosition, bool mousePressed) override;
    void Draw() override;
    void Unload() override;
};



#endif //DEATHSCENE_H
