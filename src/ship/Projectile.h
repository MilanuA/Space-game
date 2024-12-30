#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <raylib.h>

#include "../objectPooling/PoolableObject.h"

class Projectile : public PoolableObject
{
    Vector2 position = {0.0f, 0.0f};
    Vector2 velocity = {0.0f, 0.0f};

    Texture2D spriteSheet = {};
    int frameWidth = 0;
    int frameHeight = 0;
    int currentFrame = 0;

    float projectileSpeed = 0.0f;
    float rotation = 0.0f;
    float frameTime = 0.1f;
    float elapsedTime = 0.0f;

    void UpdateSprites(float deltaTime);


public:
    Projectile();
    Projectile(Vector2 startPos, Vector2 direction, float speed);

    void Init(Vector2 startPos, Vector2 direction, float speed);

    void Update(float deltaTime) override;
    void Draw() const override;
    bool CheckCollision(Rectangle target) const;
};



#endif //PROJECTILE_H
