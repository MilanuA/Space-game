#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include <vector>

#include "GameobjectsEnum.h"
#include "components/TransformComponent.h"

class Component;

class Gameobject
{
protected:
    TransformComponent transform;
    std::vector<std::unique_ptr<Component>> components;
    GameobjectsEnum tag = GameobjectsEnum::NONE;
    float screenBuffer;

public:
    explicit Gameobject(const GameobjectsEnum tag, float screenBuffer = 0) : transform(this), tag(tag), screenBuffer(screenBuffer) {}
    virtual ~Gameobject() = default;

    TransformComponent& GetTransform() { return transform; }
    [[nodiscard]] const TransformComponent& GetTransform() const { return transform; }

    [[nodiscard]] GameobjectsEnum GetTag() const { return tag; }
    [[nodiscard]] float GetScreenBuffer() const { return screenBuffer; }

    template <typename T, typename... Args>
    T& AddComponent(Args&&... args)
    {
        static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
        components.emplace_back(std::make_unique<T>(this, std::forward<Args>(args)...));
        return *dynamic_cast<T*>(components.back().get());
    }

    template <typename T>
    T* GetComponent()
    {
        for (auto& comp : components)
        {
            if (T* t = dynamic_cast<T*>(comp.get()))
            {
                return t;
            }
        }

        return nullptr;
    }

    virtual void Update(float deltaTime);
    virtual void Destroy() {}
    virtual void OnTriggerEnter2D(Gameobject *other) {}

    virtual void Draw() const;
};



#endif //GAMEOBJECT_H
