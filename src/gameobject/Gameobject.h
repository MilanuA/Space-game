#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include <vector>

#include "GameobjectsEnum.h"
#include "components/TransformComponent.h"


class Gameobject
{
protected:
    TransformComponent transform;
    std::vector<std::unique_ptr<Component>> components;
    GameobjectsEnum tag = GameobjectsEnum::NONE;

public:
    explicit Gameobject(const GameobjectsEnum tag) : transform(this), tag(tag) {}
    virtual ~Gameobject() = default;

    TransformComponent& GetTransform() { return transform; }
    const TransformComponent& GetTransform() const { return transform; }
};



#endif //GAMEOBJECT_H
