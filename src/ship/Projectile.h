#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <raylib.h>

class Projectile
{
    Vector2 position;
    Vector2 velocity;

    Texture2D spriteSheet = {};
    int frameWidth = 0;
    int frameHeight = 0;
    int currentFrame = 0;

    float projectileSpeed = 0.0f;
    float rotation = 0.0f;
    float frameTime = 0.1f;
    float elapsedTime = 0.0f;
    bool isActive = true;

    void UpdateSprites(float deltaTime);
public:
    Projectile(Vector2 startPos, Vector2 direction, float speed);
    void UpdateProjectile(float deltaTime);
    void DrawProjectile() const;
    bool CheckCollision(Rectangle target) const;

    bool IsActive() const { return isActive; }
};



#endif //PROJECTILE_H
