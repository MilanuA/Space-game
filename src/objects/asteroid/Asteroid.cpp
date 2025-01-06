#include "Asteroid.h"
#include <raymath.h>
#include "../../Helper.h"
#include "../../gameobject/components/ColliderComponent.h"
#include "../../gameobject/components/SpriteRendererComponent.h"
#include "../../systems/collisionManager/CollisionManager.h"
#include "../../systems/debug/DebugGame.h"

Asteroid::Asteroid(): Gameobject(GameobjectsEnum::Asteroid), IHealth(MAX_ASTEROID_HEALTH), scoreManager(nullptr)
{
    transform.SetScale(Vector2(ASTEROID_SPRITE_SCALE, ASTEROID_SPRITE_SCALE));
    this->AddComponent<SpriteRendererComponent>().SetTexture(LoadTexture("../resources/obstacles/asteroid.png"));
    this->AddComponent<ColliderComponent>();
}

void Asteroid::Init(Vector2 startPos, Vector2 direction,  ScoreManager &scoreManager)
{
    this->direction = direction;
    transform.SetPosition(startPos);

    currentHealth = MAX_ASTEROID_HEALTH;
    rotation = 0.0f;

    this->scoreManager = &scoreManager;
    Activate();
    CollisionManager::GetInstance().AddObject(this);
}

void Asteroid::Update(float deltaTime)
{
    Gameobject::Update(deltaTime);

    if (!isActive) return;

    transform.SetPosition(Vector2Add(transform.GetPosition(), Vector2Scale(direction, ASTEROID_SPEED * deltaTime)));

    transform.SetRotation(55.0f * deltaTime);

    if (Helper::IsOutsideScreen(transform.GetPosition(), SCREEN_BUFFER))
    {
        DeactiveAsteroid();
    }

    if (DebugGame::GetInstance().IsDebugEnabled())
         this->GetComponent<ColliderComponent>()->DrawCollisionBox();
}

void Asteroid::TakeDamage(int damage)
{
    if (!isActive) return;

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
    if (!isActive) return;

    scoreManager->UpdateScore(ASTEROID_DEATH_XP);
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
= default;

void Asteroid::Destroy()
{
    DeactiveAsteroid();
}

void Asteroid::OnTriggerEnter2D(Gameobject *other)
{
   if (other->GetTag() == GameobjectsEnum::Asteroid)
   {
       AsteroidExplosion();

       other->Destroy();
   }
}
