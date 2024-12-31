#ifndef MAINMENU_H
#define MAINMENU_H
#include "Scene.h"
#include "../ui/button/Button.h"

class MainMenuScene : public Scene
{
    Button startButton;
    Button exitButton;
    Texture2D background;
    Rectangle backgroundSourceRec;
    Rectangle backgroundDestRec;

    int animationFrameWidth;
    int currentFrame;
    float frameTime;
    float elapsedTime;

    void ButtonInteraction(Vector2 mousePosition, bool mousePressed, SceneManager &sceneManager);
    void BackgroundAnimation();
public:
    MainMenuScene();
    void Init() override;
    void Update(Vector2 mousePosition, bool mousePressed, SceneManager &sceneManager) override;
    void Draw() override;
    void Unload() override;

private:

};

#endif //MAINMENU_H
