#include "Asteroid.h"
#include <raymath.h>
#include "../../Helper.h"
#include "../../debug/DebugGame.h"
#include "../../gameobject/collisionManager/CollisionManager.h"


Asteroid::Asteroid(): Gameobject(GameobjectsEnum::Asteroid), IHealth(MAX_ASTEROID_HEALTH), scoreManager(nullptr)
{
    texture = LoadTexture("../resources/obstacles/asteroid.png");
    frameWidth = texture.width * ASTEROID_SPRITE_SCALE;
    frameHeight = texture.height * ASTEROID_SPRITE_SCALE;
}

void Asteroid::Init(Vector2 startPos, Vector2 direction,  ScoreManager &scoreManager)
{
    this->direction = direction;
    position = startPos;
    currentHealth = MAX_ASTEROID_HEALTH;
    rotation = 0.0f;

    this->scoreManager = &scoreManager;
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
        DeactiveAsteroid();
    }
}

void Asteroid::Draw() const
{
    if (!isActive) return;

    Rectangle sourceRec = {0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height)};

    Rectangle destRec = {
        position.x,
        position.y,
        static_cast<float>(frameWidth),
        static_cast<float>(frameHeight)
    };

    Vector2 origin = {
        static_cast<float>(frameWidth) / 2.0f,
        static_cast<float>(frameHeight) / 2.0f
    };

    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, WHITE);

    if (DebugGame::GetInstance().IsDebugEnabled())
    {
        Rectangle boundingBox = GetBoundingBox();

        DrawRectangleLines(
            static_cast<int>(boundingBox.x),
            static_cast<int>(boundingBox.y),
            static_cast<int>(boundingBox.width),
            static_cast<int>(boundingBox.height),
            GREEN
        );
    }
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

Rectangle Asteroid::GetBoundingBox() const
{
    if (!isActive) return {0, 0, 0, 0};

    float scaledWidth = frameWidth / 3;
    float scaledHeight = frameHeight / 3;

    return {
        position.x - scaledWidth / 2,
        position.y - scaledHeight / 2,
        scaledWidth,
        scaledHeight
    };
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
