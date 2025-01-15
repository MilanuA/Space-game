#ifndef MAINSHIP_H
#define MAINSHIP_H
#include <raylib.h>

#include "../../gameobject/Gameobject.h"
#include "../../scenes/SceneManager.h"
#include "../../systems/health/IHealth.h"
#include "../../ui/healthBar/HealthBar.h"

constexpr float SHIP_SPRITE_SCALE = 1.5f;
constexpr float SHIP_MAX_HEALTH = 100.0f;
constexpr float ASTEROID_DAMAGE = 10.0f;

class MainShip : public Gameobject, public IHealth
{
    float dragSpeed = 40.0f;

    HealthBar* playerHealthBar;
    SceneManager* scene_manager;

    void UpdatePosition();

public:
    explicit MainShip(HealthBar* healthBar) : Gameobject(GameobjectsEnum::PlayerShip, 0.0f), IHealth(SHIP_MAX_HEALTH)
    {
        playerHealthBar = healthBar;
    }

    void Init(SceneManager* scene_manager);
    [[nodiscard]] Vector2 GetPosition() const { return transform.GetPosition(); }

    /// <summary> Checks if the ship is moving fast </summary>
    /// <returns> true if the ship is moving fast, false otherwise </returns>
    [[nodiscard]] bool IsMovingFast() const;
    ~MainShip();

    void Update(float deltaTime) override;

    void Destroy() override;

    void OnTriggerEnter2D(Gameobject *other) override;

    void Draw() const override;

    void TakeDamage(int damage) override;

    void Heal(int amount) override;

    void Death() override;
};



#endif //MAINSHIP_H
