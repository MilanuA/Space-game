#include "ScoreManager.h"

#include <raylib.h>
#include <string>

void ScoreManager::UpdateScorePerSecond()
{
    static float elapsedTime = 0.0f;
    elapsedTime += GetFrameTime();

    if (elapsedTime >= 1.0f)
    {
        currentScore += scorePerSecond;
        elapsedTime = 0.0f;
    }
}

void ScoreManager::Draw() const
{
    const std::string scoreText = "Score: " + std::to_string(currentScore);

    DrawText(scoreText.c_str(), 10, 10, 20, BLACK);
}