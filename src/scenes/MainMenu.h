#ifndef MAINMENU_H
#define MAINMENU_H
#include "Scene.h"
#include "../ui/button/Button.h"

class MainMenu : public Scene
{
public:
    MainMenu();
    void Init() override;
    void Update(Vector2 mousePosition, bool mousePressed, SceneManager &sceneManager) override;
    void Draw() override;
    void Unload() override;

private:
    Button startButton;
    Button exitButton;
    Texture2D background;
    Rectangle backgroundSourceRec;
    Rectangle backgroundDestRec;
};

#endif //MAINMENU_H
