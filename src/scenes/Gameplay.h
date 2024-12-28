
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Scene.h"


class Gameplay : public  Scene
{

public:
    Gameplay();
    void Init() override;
    void Update(Vector2 mousePosition, bool mousePressed, SceneManager &sceneManager) override;
    void Draw() override;
    void Unload() override;

};



#endif //GAMEPLAY_H
