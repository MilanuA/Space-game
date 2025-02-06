#include "ScoreManager.h"

#include <raylib.h>
#include <string>

ScoreManager::ScoreManager(GameStateManager &gameStateManager): gameStateManager(gameStateManager) {
}

void ScoreManager::UpdateScorePerSecond()
{
    static float elapsedTime = 0.0f;
    static float checkStateElapsedTime = 0.0f;

    float deltaTime = GetFrameTime();
    elapsedTime += deltaTime;
    checkStateElapsedTime += deltaTime;

    if (checkStateElapsedTime >= 10.0f)
    {
        UpdateScore(SCORE_PER_SECOND);
        checkStateElapsedTime = 0.0f;
        elapsedTime = 0.0f;
    }

    if (elapsedTime >= 1.0f)
    {
        currentScore += SCORE_PER_SECOND;
        elapsedTime = 0.0f;
    }


}


void ScoreManager::Draw() const
{
    const std::string scoreText = "Score: " + std::to_string(currentScore);

    DrawText(scoreText.c_str(), 10, 10, 40, WHITE);
}

void ScoreManager::UpdateScore(int score)
{
    currentScore += score;
    gameStateManager.CheckState(currentScore);
}
