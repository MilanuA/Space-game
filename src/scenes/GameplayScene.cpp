#include "GameplayScene.h"
#include "../systems/collisionManager/CollisionManager.h"
#include "../systems/debug/DebugGame.h"
#include "../ui/console/Console.h"

GameplayScene::GameplayScene() : objectsSpawner(scoreManager, gameStateManager),
                                 mainShip(&healthBar),
                                 healthBar(LoadTexture("../resources/ui/sceneUI/healthBar/healthbar_background.png"),
                                           LoadTexture("../resources/ui/sceneUI/healthBar/healthbar_fill.png"),
                                           Vector2(GetRenderWidth(), 40)),
                                 music(), scoreManager(gameStateManager) {
}

void GameplayScene::Init(SceneManager &sceneManager)
{
    mainShip.Init(&sceneManager);

    music = LoadMusicStream("../resources/audio/spaceMusic.mp3");
    PlayMusicStream(music);
}

void GameplayScene::Update(Vector2 const mousePosition, bool const wasLeftMousePressed)
{
    UpdateMusicStream(music);

    scoreManager.UpdateScorePerSecond();
    mainShip.Update(GetFrameTime());

    CollisionManager::GetInstance().CheckCollisions();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        objectsSpawner.SpawnProjectile(mousePosition, mainShip);
    }

    if (IsKeyPressed(KEY_F2))
    {
        DebugGame& debugGame = DebugGame::GetInstance();

        if (debugGame.IsDebugEnabled())
        {
            debugGame.DisableDebug();
        }
        else
        {
            debugGame.EnableDebug();
        }
    }

    enemiesManager.UpdateEnemies();
    objectsSpawner.Update(GetFrameTime());
}

void GameplayScene::Draw()
{
    ClearBackground({ 16, 16, 73, 255 });

    scoreManager.Draw();
    objectsSpawner.Draw();
    mainShip.Draw();
    healthBar.Render();

    if (DebugGame::GetInstance().IsDebugEnabled())
    {
        DebugGame::GetInstance().ShowDebugInfo();
        Console::DrawConsole();
        gameStateManager.ShowDebug();
    }
}

void GameplayScene::Unload()
{
    UnloadMusicStream(music);
}

GameplayScene::~GameplayScene()
{
}

