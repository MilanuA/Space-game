#ifndef DEATHSCENE_H
#define DEATHSCENE_H
#include "Scene.h"
#include "../ui/button/Button.h"


class DeathScene : public  Scene
{
    Button restartButton;
    Button menuButton;
    SceneManager* scene_manager;

    void ButtonInteraction(Vector2 mousePosition, bool mousePressed);

public:
    explicit DeathScene();

    void Init(SceneManager &sceneManager) override;
    void Update(Vector2 mousePosition, bool mousePressed) override;
    void Draw() override;
    void Unload() override;
};



#endif //DEATHSCENE_H
