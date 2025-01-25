#include "GameStateManager.h"
#include "../../ui/score/ScoreManager.h"
#include "states/EarlyState.h"
#include "states/LateEarlyState.h"
#include "states/LateLateState.h"
#include "states/LateMiddleState.h"
#include "states/LateState.h"
#include "states/MiddleState.h"

GameStateManager::GameStateManager(ScoreManager &scoreManager)
    : scoreManager(scoreManager)
{
    stateMap[0] = std::make_unique<EarlyState>();
    stateMap[1] = std::make_unique<LateEarlyState>();
    stateMap[2] = std::make_unique<MiddleState>();
    stateMap[3] = std::make_unique<LateMiddleState>();
    stateMap[4] = std::make_unique<LateState>();
    stateMap[5] = std::make_unique<LateLateState>();

    currentState = std::make_unique<EarlyState>();
}

void GameStateManager::Update()
{
    int currentScore = scoreManager.GetCurrentScore();

    if (currentScore >= stateMap[currentIndex + 1]->GetNeededScore())
    {
        ++currentIndex;
        currentState = std::move(stateMap[currentIndex]);
    }
}

const IGameState & GameStateManager::GetCurrentState() const {
    return *currentState;
}
