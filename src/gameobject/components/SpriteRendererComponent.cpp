#include "SpriteRendererComponent.h"
#include "TransformComponent.h"


void SpriteRendererComponent::SetTexture(const Texture2D& tex, int frameCount)
{
    this->frameCount = frameCount;
    const Vector2& scale = owner.GetTransform().GetScale();

    texture = tex;
    frameWidth = texture.width / frameCount * scale.x;
    frameHeight = texture.height * scale.y;

    origin = {static_cast<float>(frameWidth) * scale.x / 2.0f, static_cast<float>(frameHeight) * scale.y / 2.0f};
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
    const TransformComponent &transform = owner.GetTransform();

    auto position = transform.GetPosition();

    Rectangle sourceRec = {0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    Rectangle destRect = {position.x, position.y, static_cast<float>(frameWidth), static_cast<float>(frameHeight)};

    DrawTexturePro(texture, sourceRec, destRect, origin, transform.GetRotation(), WHITE);
}
