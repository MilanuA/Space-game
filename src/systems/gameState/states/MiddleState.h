#ifndef MIDDLESTATE_H
#define MIDDLESTATE_H
#include "_baseInterface/IGameState.h"

class MiddleState : public IGameState
{
public:
    [[nodiscard]] float GetAsteroidSpeedMultiplier() const override { return 1.8f; }
    [[nodiscard]] std::string GetStateName() const override { return "Middle"; }
    [[nodiscard]] float GetNeededScore() const override {return 1000;}
};

#endif //MIDDLESTATE_H
