#include "ColliderComponent.h"

#include "SpriteRendererComponent.h"
#include "../Gameobject.h"
#include "../../systems/debug/DebugGame.h"

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
        Vector2 position = transform.GetPosition();
        Vector2 origin = sprite->GetOrigin();
        int width = sprite->GetWidth();
        int height = sprite->GetHeight();

        boundingBox = {
            position.x  - origin.x,
            position.y - origin.y,
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

void ColliderComponent::Update(float deltaTime)
{
    Component::Update(deltaTime);

    if (DebugGame::GetInstance().IsDebugEnabled())
        DrawCollisionBox();
}
