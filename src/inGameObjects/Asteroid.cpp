#include "Asteroid.h"

Asteroid::Asteroid(): IHealth(MAX_ASTEROID_HEALTH)
{
    spriteSheet = LoadTexture("../resources/obstacles/asteroid.png");
}

void Asteroid::Init(Vector2 startPos)
{
    currentHealth = MAX_ASTEROID_HEALTH;
}

void Asteroid::Update(float deltaTime)
{
    if (!isActive) return;

    if (position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight())
    {
        Deactivate();
    }
}

void Asteroid::Draw() const
{
    if (!isActive) return;

    DrawTexture(spriteSheet, position.x, position.y, WHITE);
}

void Asteroid::TakeDamage(int damage)
{
    currentHealth -= damage;

    if (currentHealth > 0) return;

    Death();
}

void Asteroid::Heal(int amount)
{
    if (!isActive) return;

    currentHealth += amount;
}

void Asteroid::Death()
{
    Deactivate();
}

Asteroid::~Asteroid()
{
}