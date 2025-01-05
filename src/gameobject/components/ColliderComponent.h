#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <raylib.h>

#include "Component.h"


class ColliderComponent : public Component
{
public:
    explicit ColliderComponent( Gameobject& owner) : Component(owner) {}

    [[nodiscard]] const Rectangle& GetBoundingBox() const;

    [[nodiscard]] bool CheckCollision(const ColliderComponent& other) const
    {
        return CheckCollisionRecs(GetBoundingBox(), other.GetBoundingBox());
    }

    void DrawCollisionBox() const;
};



#endif //COLLIDERCOMPONENT_H
