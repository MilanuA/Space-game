#ifndef LATESTATE_H
#define LATESTATE_H
#include "_baseInterface/IGameState.h"

class LateState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 2.5f; }
    [[nodiscard]] std::string GetStateName() const override { return "Late"; }
    [[nodiscard]] float GetNeededScore() const override {return 2500;}
};

#endif //LATESTATE_H
