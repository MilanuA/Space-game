#ifndef MAINSHIP_H
#define MAINSHIP_H
#include <raylib.h>

#include "../../gameobject/Gameobject.h"

constexpr float SHIP_SPRITE_SCALE = 1.5f;
class MainShip : public Gameobject
{
    float dragSpeed = 40.0f;

    void UpdatePosition();

public:
    MainShip() : Gameobject(GameobjectsEnum::PlayerShip, 0.0f){}

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
