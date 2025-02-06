#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H
#include <map>
#include <memory>
#include "states/_baseInterface/IGameState.h"

class ScoreManager;

class GameStateManager
{
    std::unique_ptr<IGameState> currentState{};
    std::map<int, std::unique_ptr<IGameState>> stateMap{};

    ScoreManager &scoreManager;
    int currentIndex = 0;

public:
    explicit GameStateManager(ScoreManager &scoreManager);
    void ShowDebug() const;
    void Update();
    [[nodiscard]] const IGameState& GetCurrentState() const;
};


#endif //GAMESTATEMANAGER_H
