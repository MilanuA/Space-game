#include "Asteroid.h"
#include <iostream>
#include <raymath.h>
#include "../../Helper.h"

Asteroid::Asteroid(): Gameobject(GameobjectsEnum::Asteroid), IHealth(MAX_ASTEROID_HEALTH)
{
    texture = LoadTexture("../resources/obstacles/asteroid.png");
    frameWidth = texture.width;
    frameHeight = texture.height;
}

void Asteroid::Init(Vector2 startPos, Vector2 direction, const ScoreManager &scoreManager)
{
    this->direction = direction;
    position = startPos;
    currentHealth = MAX_ASTEROID_HEALTH;
    rotation = 0.0f;

    Activate();
    CollisionManager::GetInstance().AddObject(this);
}

void Asteroid::Update(float deltaTime)
{
    if (!isActive) return;

    position = Vector2Add(position, Vector2Scale(direction, ASTEROID_SPEED * deltaTime));

    rotation += 55.0f * deltaTime;

    if (Helper::IsOutsideScreen(position, SCREEN_BUFFER))
    {
        Death();
    }
}

void Asteroid::Draw() const
{
    if (!isActive) return;

    Rectangle sourceRec = {0, 0, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};
    Rectangle destRec = {position.x, position.y, frameWidth * ASTEROID_SPRITE_SCALE, frameHeight * ASTEROID_SPRITE_SCALE};
    Vector2 origin = {static_cast<float>(frameWidth) / 2, static_cast<float>(frameWidth) / 2};

    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, WHITE);
}

void Asteroid::TakeDamage(int damage)
{
    std::cout << "Asteroid at position: " << position.x << ", " << position.y << " took " << damage << " damage" << std::endl;
    currentHealth -= damage;

    if (currentHealth > 0) return;

    DeactiveAsteroid();
}

void Asteroid::Heal(int amount)
{
    if (!isActive) return;

    currentHealth += amount;
}

void Asteroid::Death()
{
    DeactiveAsteroid();
}

void Asteroid::AsteroidExplosion()
{
    //TODO: Implement explosion
}

void Asteroid::DeactiveAsteroid()
{
    Deactivate();
    CollisionManager::GetInstance().RemoveObject(this);
}

Asteroid::~Asteroid()
{
}
