#include "SceneManager.h"
#include "Scene.h"

void SceneManager::RegisterScene(SceneType const type, std::unique_ptr<Scene> scene)
{
    scenes[type] = std::move(scene);
}

void SceneManager::SetCurrentScene(SceneType const type)
{
    if (currentScene)
    {
        currentScene->Unload();
    }

    currentScene = scenes[type].get();

    if (!currentScene) return;

    currentScene->Init(*this);
}

void SceneManager::Update(Vector2 const mousePosition, bool const mousePressed) const
{
    if (!currentScene) return;

    currentScene->Update(mousePosition, mousePressed);
}

void SceneManager::Draw() const
{
    if (!currentScene) return;

    currentScene->Draw();
}

void SceneManager::UnloadCurrentScene() const
{
    if (!currentScene) return;

    currentScene->Unload();
}
