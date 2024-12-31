#ifndef ASTEROID_H
#define ASTEROID_H
#include <raylib.h>

#include "../health/IHealth.h"
#include "../objectPooling/PoolableObject.h"

constexpr int MAX_ASTEROID_HEALTH = 10;

class Asteroid : public PoolableObject, public IHealth
{
    Texture2D spriteSheet = {};
    Vector2 position = {0.0f, 0.0f};

public:
    Asteroid();
    void Init(Vector2 startPos);

    void Update(float deltaTime) override;
    void Draw() const override;

    ~Asteroid() override;

    void TakeDamage(int damage) override;

    void Heal(int amount) override;

    void Death() override;
};



#endif //ASTEROID_H
