#ifndef IHEALTH_H
#define IHEALTH_H

class IHealth
{
public:
    virtual ~IHealth() = default;

    explicit IHealth(int maxHealth) : maxHealth(maxHealth), currentHealth(maxHealth) {}

    [[nodiscard]] int GetCurrentHealth() const { return currentHealth; }
    [[nodiscard]] bool IsDead() const { return currentHealth <= 0; }

    virtual void TakeDamage(int damage) = 0;
    virtual void Heal(int amount) = 0;

protected:
    int maxHealth;
    int currentHealth;
};



#endif //IHEALTH_H