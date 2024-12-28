#include "SceneManager.h"
#include "Scene.h"

void SceneManager::RegisterScene(SceneType type, std::unique_ptr<Scene> scene)
{
    scenes[type] = std::move(scene);
}

void SceneManager::SetCurrentScene(SceneType type)
{
    if (currentScene)
    {
        currentScene->Unload();
    }

    currentScene = scenes[type].get();

    if (currentScene)
    {
        currentScene->Init();
    }
}

void SceneManager::Update(Vector2 mousePosition, bool mousePressed)
{
    if (currentScene)
    {
        currentScene->Update(mousePosition, mousePressed, *this);
    }
}

void SceneManager::Draw() const
{
    if (currentScene)
    {
        currentScene->Draw();
    }
}

void SceneManager::UnloadCurrentScene() const
{
    if (currentScene)
    {
        currentScene->Unload();
    }
}
