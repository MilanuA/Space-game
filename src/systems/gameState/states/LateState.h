#ifndef LATESTATE_H
#define LATESTATE_H
#include "_baseInterface/IGameState.h"

class LateState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 2.5f; }
    [[nodiscard]] float GetSpawnRateMultiplier() const override { return 2.5f; }
    [[nodiscard]] std::string GetStateName() const override { return "Late"; }
};

#endif //LATESTATE_H
