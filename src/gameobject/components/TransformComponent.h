
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include <raylib.h>


class TransformComponent
{
    Vector2 position = {0.0f, 0.0f};
    float rotation = 0.0f;
    Vector2 scale = {1.0f, 1.0f};

public:
    [[nodiscard]] Vector2 const &GetPosition() const { return position; }
    void SetPosition(Vector2 const &position) { this->position = position; }

    [[nodiscard]] float const &GetRotation() const { return rotation; }
    void SetRotation(float const &rotation) { this->rotation = rotation; }

    [[nodiscard]] Vector2 const &GetScale() const { return scale; }
    void SetScale(Vector2 const &scale) { this->scale = scale; }
};



#endif //TRANSFORMCOMPONENT_H
