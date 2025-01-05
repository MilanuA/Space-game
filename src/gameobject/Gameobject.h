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

    int currentFrame = 0;
    GameobjectsEnum tag = GameobjectsEnum::NONE;

    float frameTime = 0.1f;
    float elapsedTime = 0.0f;

    void UpdateSprites(float deltaTime, int frameCount);

public:
    Gameobject(const GameobjectsEnum tag) : tag(tag) {}
    virtual ~Gameobject() = default;

    virtual Rectangle GetBoundingBox() const { return {0, 0, 0, 0}; }

    virtual void Update(float deltaTime) {}
    virtual void Draw() const {}
    virtual void Destroy() {}
    virtual void OnTriggerEnter2D(Gameobject* other) {}

    void DrawCollisionBox() const;

    [[nodiscard]] Vector2 GetPosition() const { return position; }
    [[nodiscard]] GameobjectsEnum GetTag() const { return tag; }
};



#endif //GAMEOBJECT_H
