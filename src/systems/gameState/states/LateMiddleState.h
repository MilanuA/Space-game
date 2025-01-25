#ifndef LATEMIDDLESTATE_H
#define LATEMIDDLESTATE_H
#include "_baseInterface/IGameState.h"

class LateMiddleState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 2.1f; }
    [[nodiscard]] float GetSpawnRateMultiplier() const override { return 2.1f; }
    [[nodiscard]] std::string GetStateName() const override { return "LateMiddle"; }
};
#endif //LATEMIDDLESTATE_H
