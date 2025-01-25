#ifndef IGAMESTATE_H
#define IGAMESTATE_H

class IGameState
{
public:
    virtual ~IGameState() = default;
    [[nodiscard]] virtual float GetAsteroidSpeedMultiplier() const = 0;
    [[nodiscard]] virtual float GetSpawnRateMultiplier() const = 0;
    [[nodiscard]] virtual float GetNeededScore() const { return 0; }
    [[nodiscard]] virtual std::string GetStateName() const = 0;
};

#endif //IGAMESTATE_H
