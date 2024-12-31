#include "Asteroid.h"

Asteroid::Asteroid(): IHealth(150)
{
}

Asteroid::Asteroid(int maxHealth): IHealth(maxHealth)
{
}

void Asteroid::Update(float deltaTime)
{
}

void Asteroid::Draw() const
{
}

void Asteroid::TakeDamage(int damage)
{
}

void Asteroid::Heal(int amount)
{
}

Asteroid::~Asteroid()
{
}