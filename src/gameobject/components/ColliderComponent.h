#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <raylib.h>

#include "Component.h"


class ColliderComponent : public Component
{
    Rectangle boundingBox;
public:
    explicit ColliderComponent(const Rectangle& box, Gameobject& owner) : Component(owner), boundingBox(box) {}

    [[nodiscard]] const Rectangle& GetBoundingBox() const { return boundingBox; }

    [[nodiscard]] bool CheckCollision(const ColliderComponent& other) const {
        return CheckCollisionRecs(boundingBox, other.boundingBox);
    }
};



#endif //COLLIDERCOMPONENT_H
