#include "Gameobject.h"


void Gameobject::Update(float deltaTime)
{
    transform.Update(deltaTime);

    for (auto& comp : components)
    {
        comp->Update(deltaTime);
    }
}

void Gameobject::Draw() const
{
    for (const auto& comp : components)
    {
        comp->Draw();
    }
}
