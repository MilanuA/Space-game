#ifndef MIDDLESTATE_H
#define MIDDLESTATE_H
#include "_baseInterface/IGameState.h"

class MiddleState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 1.8f; }
    [[nodiscard]] float GetSpawnRateMultiplier() const override { return 1.8; }
    [[nodiscard]] std::string GetStateName() const override { return "Middle"; }
};

#endif //MIDDLESTATE_H
