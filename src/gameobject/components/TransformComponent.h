
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include <raylib.h>

#include "Component.h"

class TransformComponent : public Component
{
    Vector2 position = {0.0f, 0.0f};
    float rotation = 0.0f;
    Vector2 scale = {1.0f, 1.0f};

public:
    explicit TransformComponent(Gameobject* owner) : Component(owner) {}

    [[nodiscard]] Vector2 const &GetPosition() const { return position; }
    void SetPosition(Vector2 const &position) { this->position = position; }

    [[nodiscard]] float GetRotation() const { return rotation; }
    void SetRotation(float const &rotation) { this->rotation = rotation; }

    [[nodiscard]] Vector2 const &GetScale() const { return scale; }
    void SetScale(Vector2 const &scale) { this->scale = scale; }

    void Update(float deltaTime) override;
};



#endif //TRANSFORMCOMPONENT_H
