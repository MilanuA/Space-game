#include "EnemyBase.h"

void EnemyBase::TakeDamage(int damage)
{
    currentHealth -= damage;

    if (currentHealth > 0) return;

    Death();
}

void EnemyBase::Heal(int amount)
{
}

void EnemyBase::Death()
{
    //TODO: Add animation
    Destroy();
}
