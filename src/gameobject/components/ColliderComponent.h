#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <raylib.h>

#include "Component.h"


class ColliderComponent : public Component
{
    Rectangle boundingBox = {0.0f, 0.0f, 0.0f, 0.0f};

public:
    explicit ColliderComponent( Gameobject& owner) : Component(owner) {}

    [[nodiscard]] const Rectangle& GetBoundingBox() const { return boundingBox; }

    [[nodiscard]] bool CheckCollision(const ColliderComponent& other) const
    {
        return CheckCollisionRecs(boundingBox, other.boundingBox);
    }

    void DrawCollisionBox() const;
};



#endif //COLLIDERCOMPONENT_H
