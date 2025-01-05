#include "Gameobject.h"

void Gameobject::DrawCollisionBox() const
{
    Rectangle boundingBox = GetBoundingBox();
    DrawRectangleLinesEx(boundingBox, 2, GREEN);
}

void Gameobject::UpdateSprites(float deltaTime, int frameCount)
{
    elapsedTime += deltaTime;

    if (elapsedTime >= frameTime)
    {
        currentFrame = (currentFrame + 1) % frameCount;
        elapsedTime = 0.0f;
    }
}
