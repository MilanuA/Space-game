#include "Projectile.h"
#include <cmath>

#include <raymath.h>
#include "../asteroid/Asteroid.h"
#include "../../Helper.h"
#include "../../gameobject/components/ColliderComponent.h"
#include "../../gameobject/components/SpriteRendererComponent.h"
#include "../../systems/collisionManager/CollisionManager.h"
#include "../../systems/debug/DebugGame.h"

class Asteroid;

Projectile::Projectile() : Gameobject(GameobjectsEnum::Projectile)
{
    transform.SetScale(Vector2(PROJECTILE_SPRITE_SCALE, PROJECTILE_SPRITE_SCALE));
    this->AddComponent<SpriteRendererComponent>().SetTexture(LoadTexture("../resources/ships/projectiles/projectiles.png"), 3);
    this->AddComponent<ColliderComponent>();
}

Projectile::Projectile(Vector2 startPos, Vector2 direction) : Projectile()
{
    Init(startPos, direction);
}

void Projectile::Init(Vector2 startPos, Vector2 direction)
{
    transform.SetPosition(startPos);
    velocity = Vector2Normalize(direction);

    rotation = std::atan2(velocity.y, velocity.x) * RAD2DEG;

    transform.SetRotation(rotation + 90.0f);

    Activate();
    CollisionManager::GetInstance().AddObject(this);
}

void Projectile::Update(float deltaTime)
{
    Gameobject::Update(deltaTime);

    if (!isActive) return;

    transform.SetPosition(Vector2Add(transform.GetPosition(), Vector2Scale(velocity, ASTEROID_SPEED * deltaTime)));
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

void Projectile::DeactivateProjectile()
{
    Deactivate();
    CollisionManager::GetInstance().RemoveObject(this);
}

void Projectile::Destroy()
{
    DeactivateProjectile();
}