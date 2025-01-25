#ifndef LATEEARLYSTATE_H
#define LATEEARLYSTATE_H

#include "_baseInterface/IGameState.h"

class LateEarlyState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 1.4f; }
    [[nodiscard]] float GetSpawnRateMultiplier() const override { return 1.4f; }
    std::string GetStateName() const override { return "Late Early"; }
};
#endif //LATEEARLYSTATE_H
