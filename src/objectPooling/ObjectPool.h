#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <vector>
#include <memory>
#include "PoolableObject.h"

template <typename T>
class ObjectPool
{
    static_assert(std::is_base_of<PoolableObject, T>::value, "T must inherit from PoolableObject");

    std::vector<std::unique_ptr<T>> pool;

public:
    /// <summary> Creates an object pool with the specified initial size </summary>
    /// <param name="initialSize"> The initial size of the object pool </param>
    ObjectPool(size_t initialSize)
    {
        pool.reserve(initialSize);

        for (size_t i = 0; i < initialSize; ++i)
        {
            pool.emplace_back(std::make_unique<T>());
        }
    }

    /// <summary> Returns the first available object in the pool </summary>
    /// <returns> The first available object in the pool </returns>
    T* GetAvailableObject()
    {
        for (auto& obj : pool)
        {
            if (obj->IsActive()) continue;

            obj->Activate();
            return obj.get();
        }
        return nullptr;
    }

    /// <summary> Updates all active objects in the pool </summary>
    /// <param name="deltaTime"> The time since the last frame </param>
    void UpdateAllObjects(float deltaTime)
    {
        for (auto& obj : pool)
        {
            if (!obj->IsActive()) continue;

            obj->Update(deltaTime);
        }
    }

    /// <summary> Draws all active objects in the pool </summary>
    void DrawAllObjects() const
    {
        for (const auto& obj : pool)
        {
            if (!obj->IsActive()) continue;

            obj->Draw();
        }
    }

    /// <summary> Deactivates all objects in the pool </summary>
    void DeactivateAllObjects()
    {
        for (auto& obj : pool)
        {
            obj->Deactivate();
        }
    }

    /// <summary> Returns the number of active objects in the pool </summary>
    /// <returns> The number of active objects in the pool </returns>
    int GetActiveObjectCount() const
    {
        int count = 0;
        for (const auto& obj : pool)
        {
            if (obj->IsActive()) count++;
        }
        return count;
    }
};

#endif // OBJECT_POOL_H