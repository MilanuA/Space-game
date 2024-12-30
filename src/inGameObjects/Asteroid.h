#ifndef ASTEROID_H
#define ASTEROID_H
#include "../health/IHealth.h"
#include "../objectPooling/PoolableObject.h"


class Asteroid : public PoolableObject, public IHealth
{

public:
    explicit Asteroid(int maxHealth);

    void Update(float deltaTime) override;
    void Draw() const override;

    ~Asteroid() override;

    void TakeDamage(int damage) override;

    void Heal(int amount) override;
};



#endif //ASTEROID_H
