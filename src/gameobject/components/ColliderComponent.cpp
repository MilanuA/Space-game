#include "ColliderComponent.h"

#include "SpriteRendererComponent.h"
#include "../Gameobject.h"

const Rectangle &ColliderComponent::GetBoundingBox() const
{
    auto* sprite = owner->GetComponent<SpriteRendererComponent>();
    if (!sprite)
    {
        boundingBox = {0.0f, 0.0f, 0.0f, 0.0f};
    }
    else
    {
        const TransformComponent& transform = owner->GetTransform();
        Vector2 position = sprite->GetOrigin();
        int width = sprite->GetWidth() / 3;
        int height = sprite->GetHeight() / 3;
        boundingBox = {
            position.x,
            position.y,
            static_cast<float>(width),
            static_cast<float>(height)
        };
    }
    return boundingBox;
}

void ColliderComponent::DrawCollisionBox() const
{
    DrawRectangleLinesEx(GetBoundingBox(), 2, GREEN);
}
