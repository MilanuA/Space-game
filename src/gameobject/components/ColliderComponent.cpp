#include "ColliderComponent.h"

void ColliderComponent::DrawCollisionBox() const
{
    DrawRectangleLinesEx(boundingBox, 2, GREEN);
}