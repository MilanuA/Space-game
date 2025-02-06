#ifndef EARLYSTATE_H
#define EARLYSTATE_H
#include "_baseInterface/IGameState.h"

class EarlyState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 1.0f; }
    [[nodiscard]] std::string GetStateName() const override { return "Early"; }
    [[nodiscard]] float GetNeededScore() const override {return 0;}
};

#endif //EARLYSTATE_H
