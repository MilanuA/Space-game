#ifndef IHEALTH_H
#define IHEALTH_H

class IHealth
{
protected:
    float maxHealth;
    float currentHealth;

public:
    virtual ~IHealth() = default;

    explicit IHealth(float maxHealth) : maxHealth(maxHealth), currentHealth(maxHealth) {}

    [[nodiscard]] float GetCurrentHealth() const { return currentHealth; }
    [[nodiscard]] bool IsDead() const { return currentHealth <= 0; }

    virtual void TakeDamage(int damage) = 0;
    virtual void Heal(int amount) = 0;
    virtual void Death() = 0;

};



#endif //IHEALTH_H