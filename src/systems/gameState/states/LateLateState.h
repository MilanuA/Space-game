#ifndef LATELATESTATE_H
#define LATELATESTATE_H
#include "_baseInterface/IGameState.h"

class LateLateState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 3.5f; }
    [[nodiscard]] std::string GetStateName() const override { return "Late_Late"; }
    [[nodiscard]] float GetNeededScore() const override {return 3000;}
};
#endif //LATELATESTATE_H
