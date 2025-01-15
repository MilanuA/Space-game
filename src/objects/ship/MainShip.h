#ifndef MAINSHIP_H
#define MAINSHIP_H
#include <raylib.h>

#include "../../gameobject/Gameobject.h"
#include "../../ui/healthBar/HealthBar.h"

constexpr float SHIP_SPRITE_SCALE = 1.5f;
constexpr float SHIP_MAX_HEALTH = 100.0f;
constexpr float ASTEROID_DAMAGE = 10.0f;

class MainShip : public Gameobject
{
    float dragSpeed = 40.0f;

    HealthBar *playerHealthBar;

    void UpdatePosition();

public:
    explicit MainShip(HealthBar* healthBar) : Gameobject(GameobjectsEnum::PlayerShip, 0.0f) {
        playerHealthBar = healthBar;
    }

    void Init();
    [[nodiscard]] Vector2 GetPosition() const { return transform.GetPosition(); }

    /// <summary> Checks if the ship is moving fast </summary>
    /// <returns> true if the ship is moving fast, false otherwise </returns>
    [[nodiscard]] bool IsMovingFast() const;
    ~MainShip();

    void Update(float deltaTime) override;

    void Destroy() override;

    void OnTriggerEnter2D(Gameobject *other) override;

    void Draw() const override;
};



#endif //MAINSHIP_H
