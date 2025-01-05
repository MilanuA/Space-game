#include "ColliderComponent.h"

#include "SpriteRendererComponent.h"

const Rectangle &ColliderComponent::GetBoundingBox() const
{
    auto* sprite = owner.GetComponent<SpriteRendererComponent>();

    if (!sprite) return {0.0f, 0.0f, 0.0f, 0.0f};

    const TransformComponent &transform = owner.GetTransform();
    Vector2 position = transform.GetPosition();

    return {
        position.x,
        position.y,
        static_cast<float>(sprite->GetWidth()),
        static_cast<float>(sprite->GetHeight())
    };
}

void ColliderComponent::DrawCollisionBox() const
{
    DrawRectangleLinesEx(GetBoundingBox(), 2, GREEN);
}
