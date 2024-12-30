#include "Projectile.h"
#include <cmath>
#include <iostream>
#include <raymath.h>

Projectile::Projectile()
{
    spriteSheet = LoadTexture("../resources/ships/projectiles/projectiles.png");
    frameWidth = spriteSheet.width / 3;
    frameHeight = spriteSheet.height;
}

Projectile::Projectile(Vector2 startPos, Vector2 direction, float speed) : Projectile()
{
    Init(startPos, direction, speed);
}

void Projectile::Init(Vector2 startPos, Vector2 direction, float speed)
{
    position = startPos;
    velocity = Vector2Normalize(direction);
    projectileSpeed = speed;

    rotation = std::atan2(velocity.y, velocity.x) * RAD2DEG;

    Activate();
}


void Projectile::Update(float deltaTime)
{
    if (!isActive) return;

    position.x += velocity.x * deltaTime * projectileSpeed;
    position.y += velocity.y * deltaTime * projectileSpeed;


    UpdateSprites(deltaTime);

    // Deactivate if out of bounds
    if (position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight())
    {
       Deactivate();
    }
}

void Projectile::Draw() const
{
    if (!isActive) return;

    Rectangle sourceRect = {static_cast<float>(currentFrame * frameWidth), 0.0f, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};
    Rectangle destRect = {position.x, position.y, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};
    Vector2 origin = {static_cast<float>(frameWidth) / 2, static_cast<float>(frameHeight) / 2};

    DrawTexturePro(spriteSheet, sourceRect, destRect, origin, rotation + 90, WHITE);
}


bool Projectile::CheckCollision(Rectangle target) const
{
    Rectangle projectileRect = {position.x - static_cast<float>(frameWidth) / 2, position.y - static_cast<float>(frameHeight) / 2, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};
    return CheckCollisionRecs(projectileRect, target);
}

void Projectile::UpdateSprites(float deltaTime)
{
    elapsedTime += deltaTime;

    if (elapsedTime >= frameTime)
    {
        currentFrame = (currentFrame + 1) % 3;
        elapsedTime = 0.0f;
    }
}