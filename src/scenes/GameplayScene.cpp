#include "GameplayScene.h"

#include <raymath.h>

#include "../ship/Projectile.h"

GameplayScene::GameplayScene() : music()
{
}

void GameplayScene::Init()
{
    mainShip.Init();

    music = LoadMusicStream("../resources/audio/spaceMusic.mp3");
    PlayMusicStream(music);
}

void GameplayScene::Update(Vector2 const mousePosition, bool const wasLeftMousePressed, SceneManager &sceneManager)
{
    UpdateMusicStream(music);

    scoreManager.UpdateScorePerSecond();
    mainShip.UpdatePosition(mousePosition);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        objectsSpawner.SpawnProjectile(mousePosition, mainShip);
    }

    objectsSpawner.Update(GetFrameTime());
}

void GameplayScene::Draw()
{
    ClearBackground(Color(16,16,73, 255));

    scoreManager.Draw();
    mainShip.DrawShip();
    objectsSpawner.Draw();
}
void GameplayScene::Unload()
{
    UnloadMusicStream(music);
}


GameplayScene::~GameplayScene()
{
}

