#ifndef ASTEROID_H
#define ASTEROID_H
#include <raylib.h>
#include "../../gameobject/Gameobject.h"
#include "../../systems/animation/Animation.h"
#include "../../systems/health/IHealth.h"
#include "../../systems/objectPooling/PoolableObject.h"
#include "../../ui/score/ScoreManager.h"

constexpr int MAX_ASTEROID_HEALTH = 20;
constexpr int ASTEROID_BASE_SPEED = 400;
constexpr float SCREEN_BUFFER = 20.0f;
constexpr float ASTEROID_SPRITE_SCALE = 2.0f;
constexpr float ASTEROID_DEATH_XP = 50;


class Asteroid : public Gameobject, public PoolableObject, public IHealth
{
    Vector2 direction = {0.0f, 0.0f};
    bool playingExplosion = false;
    int speed = ASTEROID_BASE_SPEED;

    void DeactiveAsteroid();

    Animation* explosionAnimation;
    ScoreManager *scoreManager{};

public:
    Asteroid();

    void Init(Vector2 startPos, Vector2 direction, ScoreManager &scoreManager);

    void Update(float deltaTime) override;

    void TakeDamage(int damage) override;
    void Heal(int amount) override;
    void Death() override;

    ~Asteroid() override;

    void Destroy() override;

    void OnTriggerEnter2D(Gameobject *other) override;

    void Draw() const override;

    void AsteroidExplosion();
};



    #endif //ASTEROID_H
