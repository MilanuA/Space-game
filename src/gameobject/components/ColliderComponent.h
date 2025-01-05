#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <raylib.h>


class ColliderComponent
{
    Rectangle boundingBox;
public:
    explicit ColliderComponent(const Rectangle& box) : boundingBox(box) {}

    [[nodiscard]] const Rectangle& GetBoundingBox() const { return boundingBox; }

    [[nodiscard]] bool CheckCollision(const ColliderComponent& other) const {
        return CheckCollisionRecs(boundingBox, other.boundingBox);
    }
};



#endif //COLLIDERCOMPONENT_H
