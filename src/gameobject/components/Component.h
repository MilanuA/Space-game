#ifndef COMPONENT_H
#define COMPONENT_H

class Gameobject;

class Component
{
protected:
    Gameobject* owner;
public:
    explicit Component(Gameobject* owner) : owner(owner) {}
    virtual ~Component() = default;

    virtual void Update(float deltaTime) {}
    virtual void Draw() {}
};



#endif //COMPONENT_H
