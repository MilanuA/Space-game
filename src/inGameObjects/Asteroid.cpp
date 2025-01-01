#include "Asteroid.h"

#include <iostream>
#include <raymath.h>

#include "../Helper.h"

Asteroid::Asteroid(): IHealth(MAX_ASTEROID_HEALTH), rotation(0.0f)
{
    spriteSheet = LoadTexture("../resources/obstacles/asteroid.png");
}

void Asteroid::Init(Vector2 startPos)
{
    position = startPos;
    currentHealth = MAX_ASTEROID_HEALTH;
    rotation = 0.0f;
}

void Asteroid::Update(float deltaTime)
{
    if (!isActive) return;

    position = Vector2Add(position, Vector2Scale(direction, ASTEROID_SPEED * deltaTime));

    rotation += 55.0f * deltaTime;

    if (Helper::IsOutsideScreen(position, SCREEN_BUFFER))
    {
        Deactivate();
    }
}

void Asteroid::Draw() const
{
    if (!isActive) return;


    Rectangle sourceRec = {0, 0, static_cast<float>(spriteSheet.width), static_cast<float>(spriteSheet.height)};
    Rectangle destRec = {position.x, position.y, spriteSheet.width * ASTEROID_SPRITE_SCALE, spriteSheet.height * ASTEROID_SPRITE_SCALE};
    Vector2 origin = {static_cast<float>(spriteSheet.width) / 2, static_cast<float>(spriteSheet.height) / 2};

    DrawTexturePro(spriteSheet, sourceRec, destRec, origin, rotation, WHITE);
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

void Asteroid::SetDirection(Vector2 direction)
{
    //log direction
    std::cout << "Asteroid direction: (" << direction.x << ", " << direction.y << ")" << std::endl;
    this->direction = direction;
}

Asteroid::~Asteroid()
{
}