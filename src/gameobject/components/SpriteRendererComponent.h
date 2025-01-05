
#ifndef SPRITERENDERERCOMPONENT_H
#define SPRITERENDERERCOMPONENT_H
#include <raylib.h>

#include "Component.h"


class SpriteRendererComponent : public Component
{
    Texture2D texture = { };

    Vector2 origin = { 0.0f, 0.0f };

    int frameWidth = 0;
    int frameHeight = 0;
    int currentFrame = 0;
    int frameCount = 1;

    float frameTime = 0.1f;
    float elapsedTime = 0.0f;

    void UpdateSprites(float deltaTime, int frameCount);

public:
    explicit SpriteRendererComponent(Gameobject &owner) : Component(owner) {}

    void SetTexture(const Texture2D& tex, int width, int height, int frameCount = 1);

    [[nodiscard]] Vector2 const &GetOrigin() const { return origin; }

    void Update(float deltaTime) override;
    void Draw() override;
};



#endif //SPRITERENDERERCOMPONENT_H
