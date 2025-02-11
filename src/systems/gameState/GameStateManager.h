#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H
#include <map>
#include <memory>

#include "../debug/ILoggable.h"
#include "states/_baseInterface/IGameState.h"

class ScoreManager;

class GameStateManager : public ILoggable
{
    std::unique_ptr<IGameState> currentState{};
    std::map<int, std::unique_ptr<IGameState>> stateMap{};
    int currentIndex = 0;

public:
    explicit GameStateManager();

    void CheckState(int currentScore);
    [[nodiscard]] const IGameState& GetCurrentState() const;

    [[nodiscard]] std::string Log() const override
    {
        return "Current State: " + currentState->GetStateName();
    }
};


#endif //GAMESTATEMANAGER_H
