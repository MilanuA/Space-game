#include "TransformComponent.h"
#include "../Gameobject.h"
#include "../../Helper.h"

void TransformComponent::Update(float deltaTime)
{
    Component::Update(deltaTime);

    if (Helper::IsOutsideScreen(GetPosition(), owner->GetScreenBuffer()))
    {
        owner->Destroy();
    }
}
