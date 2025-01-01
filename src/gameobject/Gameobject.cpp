#include "Gameobject.h"

Rectangle Gameobject::GetBoundingBox() const
{
    float width = static_cast<float>(texture.width);
    float height = static_cast<float>(texture.height);
    return {static_cast<float>(position.x), static_cast<float>(position.y), width, height};
}