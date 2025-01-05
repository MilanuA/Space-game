#ifndef COMPONENT_H
#define COMPONENT_H
#include "../Gameobject.h"


class Component
{
protected:
    Gameobject& owner;
public:
    explicit Component(Gameobject& owner) : owner(owner) {}
    virtual ~Component() = default;

    virtual void Update(float deltaTime) {}
    virtual void Draw() {}
};



#endif //COMPONENT_H
