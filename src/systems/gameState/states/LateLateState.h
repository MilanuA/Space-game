#ifndef LATELATESTATE_H
#define LATELATESTATE_H
#include "_baseInterface/IGameState.h"

class LateLateState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 3.5f; }
    [[nodiscard]] float GetSpawnRateMultiplier() const override { return 3.5f; }
    [[nodiscard]] std::string GetStateName() const override { return "LateLate"; }
};
#endif //LATELATESTATE_H
