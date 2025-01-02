#include "Gameobject.h"

void Gameobject::DrawCollisionBox() const
{
    Rectangle boundingBox = GetBoundingBox();
    DrawRectangleLinesEx(boundingBox, 2, GREEN);
}
