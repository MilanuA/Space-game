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
    SceneManager* sceneManager;

    int animationFrameWidth;
    int currentFrame;
    float frameTime;
    float elapsedTime;

    void ButtonInteraction(Vector2 mousePosition, bool mousePressed);
    void BackgroundAnimation();

public:
    explicit MainMenuScene();
    void Init(SceneManager &sceneManager) override;
    void Update(Vector2 mousePosition, bool mousePressed) override;
    void Draw() override;
    void Unload() override;
};

#endif //MAINMENU_H
