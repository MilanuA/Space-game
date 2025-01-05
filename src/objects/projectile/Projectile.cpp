#include "Projectile.h"
#include <cmath>

#include <raymath.h>
#include "../asteroid/Asteroid.h"
#include "../../Helper.h"
#include "../../systems/collisionManager/CollisionManager.h"
#include "../../systems/debug/DebugGame.h"
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

    UpdateSprites(deltaTime, 3);

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
    Vector2 origin = {static_cast<float>(frameWidth) * PROJECTILE_SPRITE_SCALE / 2, static_cast<float>(frameHeight) * PROJECTILE_SPRITE_SCALE / 2};

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

Rectangle Projectile::GetBoundingBox() const
{
    float scaledWidth = frameWidth ;
    float scaledHeight = frameHeight ;

    return {
        position.x - scaledWidth / 2,
        position.y - scaledHeight / 2,
        scaledWidth,
        scaledHeight
    };
}


void Projectile::DeactivateProjectile()
{
    Deactivate();
    CollisionManager::GetInstance().RemoveObject(this);
}

void Projectile::Destroy()
{
    DeactivateProjectile();
}