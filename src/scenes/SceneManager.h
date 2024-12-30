#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <memory>
#include <raylib.h>
#include <unordered_map>

class Scene;

enum class SceneType
{
    MAIN_MENU,
    GAME
};

class SceneManager
{
    std::unordered_map<SceneType, std::unique_ptr<Scene>> scenes;
    Scene* currentScene = nullptr;
    bool exitGame = false;

public:
    
    void RegisterScene(SceneType type, std::unique_ptr<Scene> scene);
    void SetCurrentScene(SceneType type);
    void Update(Vector2 mousePosition, bool mousePressed);
    void Draw() const;
    void UnloadCurrentScene() const;

    bool ShouldExit() const { return exitGame; }
    void Exit() { exitGame = true; }
};

#endif //SCENEMANAGER_H
