
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <raylib.h>

#include "GameobjectsEnum.h"


class Gameobject
{
protected:
    Vector2 position = {0.0f, 0.0f};
    Texture2D texture = {};
    int frameWidth = 0;
    int frameHeight = 0;
    GameobjectsEnum tag = GameobjectsEnum::NONE;

public:
    Gameobject(const GameobjectsEnum tag) : tag(tag) {}
    virtual ~Gameobject() = default;

    [[nodiscard]] virtual Rectangle GetBoundingBox() const;

    virtual void Update(float deltaTime) {}
    virtual void Draw() const {}

    virtual void OnTriggerEnter2D(Gameobject* other) {};
    [[nodiscard]] Vector2 GetPosition() const { return position; }
    [[nodiscard]] GameobjectsEnum GetTag() const { return tag; }
};



#endif //GAMEOBJECT_H
