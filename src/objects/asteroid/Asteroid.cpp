#include "Asteroid.h"
#include <raymath.h>
#include "../../Helper.h"
#include "../../gameobject/components/ColliderComponent.h"
#include "../../gameobject/components/SpriteRendererComponent.h"
#include "../../systems/collisionManager/CollisionManager.h"

Asteroid::Asteroid(): Gameobject(GameobjectsEnum::Asteroid, SCREEN_BUFFER), IHealth(MAX_ASTEROID_HEALTH)
{
    transform.SetScale(Vector2(ASTEROID_SPRITE_SCALE, ASTEROID_SPRITE_SCALE));
    this->AddComponent<SpriteRendererComponent>().SetTexture(LoadTexture("../resources/obstacles/asteroid.png"));
    this->AddComponent<ColliderComponent>().SetCustomCollisionDecreaser(1.3f);

    explosionAnimation = new Animation(LoadTexture("../resources/obstacles/asteroid_explode.png"), 8, 0.1f);
}

void Asteroid::Init(Vector2 startPos, Vector2 direction,  ScoreManager &scoreManager)
{
    this->direction = direction;
    transform.SetPosition(startPos);

    currentHealth = MAX_ASTEROID_HEALTH;

    playingExplosion = false;
    this->scoreManager = &scoreManager;
    Activate();
    CollisionManager::GetInstance().AddObject(this);
}

void Asteroid::Update(float deltaTime)
{
    Gameobject::Update(deltaTime);

    if (!isActive) return;

    if (playingExplosion)
    {
        explosionAnimation->Update(deltaTime);

        if (!explosionAnimation->IsPlaying())
        {
            DeactiveAsteroid();
        }
        return;
    }

    transform.SetPosition(Vector2Add(transform.GetPosition(), Vector2Scale(direction, ASTEROID_SPEED * deltaTime)));

    transform.SetRotation(55.0f * deltaTime);
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
    std::cout << "| Asteroid explosion |: " << this << std::endl;
    if (playingExplosion) return;

    explosionAnimation->Play(transform.GetPosition(), ASTEROID_SPRITE_SCALE, transform.GetRotation());
    playingExplosion = true;
    CollisionManager::GetInstance().RemoveObject(this);
}

void Asteroid::DeactiveAsteroid()
{
    Deactivate();
    CollisionManager::GetInstance().RemoveObject(this);
}

Asteroid::~Asteroid()
{
    delete explosionAnimation;
}

void Asteroid::Destroy()
{
    DeactiveAsteroid();
}

void Asteroid::OnTriggerEnter2D(Gameobject *other)
{
    if (playingExplosion || other == this) return;
    std::cout << "| Asteroid: |" << this << " collided with: " << other << std::endl;

    Asteroid* asteroid = dynamic_cast<Asteroid*>(other);
    if (asteroid == nullptr) return;

    asteroid->AsteroidExplosion();
    AsteroidExplosion();
}

void Asteroid::Draw() const
{
    if (playingExplosion)
    {
        explosionAnimation->Draw();
        return;
    }

    Gameobject::Draw();
}
