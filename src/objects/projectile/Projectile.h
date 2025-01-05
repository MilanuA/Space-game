#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <raylib.h>

#include "../../gameobject/Gameobject.h"
#include "../../objectPooling/PoolableObject.h"

constexpr int PROJECTILE_SPRITE_SCALE = 2.0f;
constexpr float PROJECTILE_SPEED = 350.0f;
constexpr float PROJECTILE_DAMAGE = 10.0f;

class Projectile : public Gameobject, public PoolableObject
{
    Vector2 velocity = {0.0f, 0.0f};
    float rotation = 0.0f;

    void DeactivateProjectile();
public:
    Projectile();
    Projectile(Vector2 startPos, Vector2 direction);

    void Init(Vector2 startPos, Vector2 direction);

    void Update(float deltaTime) override;
    void Draw() const override;

    void OnTriggerEnter2D(Gameobject *other) override;

    Rectangle GetBoundingBox() const override;

    void Destroy() override;
};



#endif //PROJECTILE_H
