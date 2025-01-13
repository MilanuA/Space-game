#include "SpriteRendererComponent.h"

#include <iostream>

#include "TransformComponent.h"
#include "../Gameobject.h"


void SpriteRendererComponent::SetTexture(const Texture2D& tex, int frameCount)
{
    this->frameCount = frameCount;

    texture = tex;
    frameWidth = texture.width / frameCount;
    frameHeight = texture.height;
    currentFrame = 1;

    origin = {static_cast<float>(frameWidth)/ 2.0f, static_cast<float>(frameHeight) / 2.0f};
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

void SpriteRendererComponent::Update(float deltaTime)
{
    Component::Update(deltaTime);

    UpdateSprites(deltaTime, frameCount);
}

void SpriteRendererComponent::Draw()
{
    const TransformComponent &transform = owner->GetTransform();

    Vector2 position = transform.GetPosition();
    Vector2 scale = transform.GetScale();

    Rectangle sourceRec = {static_cast<float>(currentFrame * frameWidth), 0.0f, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};
    Rectangle destRect = {position.x, position.y, static_cast<float>(frameWidth) * scale.x , static_cast<float>(frameHeight) * scale.y};
    Vector2 scaledOrigin = {origin.x * scale.x, origin.y * scale.y};

    float rotation = transform.GetRotation();
    DrawTexturePro(texture, sourceRec, destRect, scaledOrigin , transform.GetRotation(), WHITE);
}
