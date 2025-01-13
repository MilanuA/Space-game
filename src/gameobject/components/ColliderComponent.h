#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <raylib.h>

#include "Component.h"


class ColliderComponent : public Component
{
    mutable Rectangle boundingBox;

public:
    explicit ColliderComponent( Gameobject* owner) : Component(owner) {}

    [[nodiscard]] const Rectangle& GetBoundingBox() const;

    [[nodiscard]] bool CheckCollision(const ColliderComponent& other) const
    {
        return CheckCollisionRecs(GetBoundingBox(), other.GetBoundingBox());
    }

    void DrawCollisionBox() const;
    void Update(float deltaTime) override;
};



#endif //COLLIDERCOMPONENT_H
