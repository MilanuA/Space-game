#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <raylib.h>

#include "Component.h"


class ColliderComponent : public Component
{
    mutable Rectangle boundingBox;
    float customCollisionDecreaser = 1.0f;
public:
    explicit ColliderComponent( Gameobject* owner) : Component(owner) {}

    [[nodiscard]] const Rectangle& GetBoundingBox() const;

    [[nodiscard]] bool CheckCollision(const ColliderComponent& other) const
    {
        return CheckCollisionRecs(GetBoundingBox(), other.GetBoundingBox());
    }

    void SetCustomCollisionDecreaser(float value) { customCollisionDecreaser = value; }

    void DrawCollisionBox() const;
    void Update(float deltaTime) override;
};



#endif //COLLIDERCOMPONENT_H
