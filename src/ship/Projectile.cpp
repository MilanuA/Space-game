#include "Projectile.h"
#include <cmath>

Projectile::Projectile(Vector2 startPos, Vector2 direction, float speed): position(), velocity()
{
    position = startPos;
    velocity = direction;

    projectileSpeed = speed;
    spriteSheet = LoadTexture("../graphics/ships/projectiles/projectiles.png");
    frameWidth = spriteSheet.width / 3;
    frameHeight = spriteSheet.height;

    rotation = std::atan2(velocity.y, velocity.x) * -57.29578f;
}

void Projectile::UpdateProjectile(float deltaTime)
{
    if (!isActive) return;

    position.x += velocity.x * deltaTime * projectileSpeed;
    position.y += velocity.y * deltaTime * projectileSpeed;

    UpdateSprites(deltaTime);

    // Deactivate if out of bounds
    if (position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight())
    {
        isActive = false;
    }
}

void Projectile::DrawProjectile() const
{
    if (!isActive) return;

    Rectangle sourceRect = {static_cast<float>(currentFrame * frameWidth), 0.0f, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};
    Rectangle destRect = {position.x, position.y, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};
    Vector2 origin = {static_cast<float>(frameWidth) / 2, static_cast<float>(frameHeight) / 2};
    DrawTexturePro(spriteSheet, sourceRect, destRect, origin, rotation, WHITE);
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