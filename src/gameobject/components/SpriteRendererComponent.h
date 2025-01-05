
#ifndef SPRITERENDERERCOMPONENT_H
#define SPRITERENDERERCOMPONENT_H
#include <raylib.h>


class SpriteRendererComponent
{
    Texture2D texture = { };

    Vector2 origin = { 0.0f, 0.0f };

    int frameWidth = 0;
    int frameHeight = 0;
    int currentFrame = 0;

    float frameTime = 0.1f;
    float elapsedTime = 0.0f;

public:
    void SetTexture(const Texture2D& tex, int width, int height);
    void UpdateSprites(float deltaTime, int frameCount);
    void Draw(Vector2 position);

    [[nodiscard]] Vector2 const &GetOrigin() const { return origin; }
};



#endif //SPRITERENDERERCOMPONENT_H
