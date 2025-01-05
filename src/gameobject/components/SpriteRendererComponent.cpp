#include "SpriteRendererComponent.h"

void SpriteRendererComponent::SetTexture(const Texture2D &tex, int width, int height)
{
    texture = tex;
    frameWidth = width;
    frameHeight = height;

    origin = {static_cast<float>(frameWidth) / 2, static_cast<float>(frameHeight) / 2};
}

void SpriteRendererComponent::UpdateSprites(float deltaTime, int frameCount)
{
    //there is no need to update sprites when there is only one frame
    if (frameCount == 1) return;

    elapsedTime += deltaTime;

    if (elapsedTime < frameTime) return;

    elapsedTime = 0.0f;
    currentFrame = (currentFrame + 1) % frameCount;
}

void SpriteRendererComponent::Draw(Vector2 position)
{
    Rectangle sourceRec = {0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    Rectangle destRect = {position.x, position.y, (float)frameWidth, (float)frameHeight};

    DrawTexturePro(texture, sourceRec, destRect, origin, 0.0f, WHITE);
}
