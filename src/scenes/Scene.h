#ifndef SCENE_H
#define SCENE_H
#include <raylib.h>

#include "SceneManager.h"

class Scene
{
public:
    virtual ~Scene() = default;

    virtual void Init(SceneManager &sceneManager) = 0;
    virtual void Update(Vector2 mousePosition, bool mousePressed) = 0;
    virtual void Draw() = 0;
    virtual void Unload() = 0;
};

#endif //SCENE_H
