#include "Projectile.h"
#include <cmath>
#include <iostream>
#include <raymath.h>

#include "../Helper.h"
#include "../debug/DebugGame.h"
#include "../gameobject/inGameObjects/Asteroid.h"
class Asteroid;

Projectile::Projectile() : Gameobject(GameobjectsEnum::Projectile)
{
    texture = LoadTexture("../resources/ships/projectiles/projectiles.png");
    frameWidth = texture.width / 3;
    frameHeight = texture.height;
}

Projectile::Projectile(Vector2 startPos, Vector2 direction) : Projectile()
{
    Init(startPos, direction);
}

void Projectile::Init(Vector2 startPos, Vector2 direction)
{
    position = startPos;
    velocity = Vector2Normalize(direction);

    rotation = std::atan2(velocity.y, velocity.x) * RAD2DEG;

    Activate();
    CollisionManager::GetInstance().AddObject(this);
}

void Projectile::Update(float deltaTime)
{
    if (!isActive) return;

    position.x += velocity.x * deltaTime * PROJECTILE_SPEED;
    position.y += velocity.y * deltaTime * PROJECTILE_SPEED;

    UpdateSprites(deltaTime);

    // Deactivate if out of bounds
    if (Helper::IsOutsideScreen(position))
    {
        DeactivateProjectile();
    }

    if (DebugGame::GetInstance().IsDebugEnabled())
        DrawCollisionBox();
}

void Projectile::Draw() const
{
    if (!isActive) return;

    Rectangle sourceRect = {static_cast<float>(currentFrame * frameWidth), 0.0f, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};
    Rectangle destRect = {position.x, position.y, static_cast<float>(frameWidth) * PROJECTILE_SPRITE_SCALE, static_cast<float>(frameHeight) * PROJECTILE_SPRITE_SCALE};
    Vector2 origin = {static_cast<float>(frameWidth) / 2, static_cast<float>(frameHeight) / 2};

    DrawTexturePro(texture, sourceRect, destRect, origin, rotation + 90, WHITE);
}

void Projectile::OnTriggerEnter2D(Gameobject *other)
{
    Gameobject::OnTriggerEnter2D(other);

    if (other->GetTag() != GameobjectsEnum::Asteroid) return;

    if (Asteroid* asteroid = dynamic_cast<Asteroid*>(other))
    {
        asteroid->TakeDamage(PROJECTILE_DAMAGE);

        DeactivateProjectile();
    }
}

// TODO: Redo this, cuz it still doesn't fit the sprite
Rectangle Projectile::GetBoundingBox() const
{
    float scaledWidth = frameWidth * PROJECTILE_SPRITE_SCALE;
    float scaledHeight = frameHeight * PROJECTILE_SPRITE_SCALE;

    return {
        position.x - scaledWidth / 2,
        position.y - scaledHeight / 2,
        scaledWidth,
        scaledHeight
    };
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

void Projectile::DeactivateProjectile()
{
    Deactivate();
    CollisionManager::GetInstance().RemoveObject(this);
}