#ifndef LATEEARLYSTATE_H
#define LATEEARLYSTATE_H

#include "_baseInterface/IGameState.h"

class LateEarlyState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 1.4f; }
    std::string GetStateName() const override { return "Late_Early"; }
    [[nodiscard]] float GetNeededScore() const override {return 500;}
};
#endif //LATEEARLYSTATE_H
