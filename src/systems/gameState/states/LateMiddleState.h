#ifndef LATEMIDDLESTATE_H
#define LATEMIDDLESTATE_H
#include "_baseInterface/IGameState.h"

class LateMiddleState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 2.1f; }
    [[nodiscard]] std::string GetStateName() const override { return "Late_Middle"; }
    [[nodiscard]] float GetNeededScore() const override {return 1500;}
};
#endif //LATEMIDDLESTATE_H
