    #ifndef ASTEROID_H
    #define ASTEROID_H
    #include <raylib.h>
    #include "../Gameobject.h"
    #include "../../health/IHealth.h"
    #include "../../objectPooling/PoolableObject.h"
    #include "../../ui/score/ScoreManager.h"

    constexpr int MAX_ASTEROID_HEALTH = 20;
    constexpr int ASTEROID_SPEED = 200;
    constexpr float SCREEN_BUFFER = 20.0f;
    constexpr float ASTEROID_SPRITE_SCALE = 2.0f;

    class Asteroid : public Gameobject, public PoolableObject, public IHealth
    {
        Vector2 direction = {0.0f, 0.0f};
        float rotation = 0.0f;

        void AsteroidExplosion();
        void DeactiveAsteroid();
    public:
        Asteroid();


        void Init(Vector2 startPos, Vector2 direction, const ScoreManager &scoreManager);

        void Update(float deltaTime) override;
        void Draw() const override;

        ~Asteroid() override;

        void TakeDamage(int damage) override;

        void Heal(int amount) override;

        void Death() override;
    };



    #endif //ASTEROID_H
