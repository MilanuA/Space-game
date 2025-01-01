#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <memory>
#include <vector>
#include "../Gameobject.h"

class CollisionManager
{
    std::vector<Gameobject*> objects;

    CollisionManager() = default;
    ~CollisionManager() = default;

    CollisionManager(const CollisionManager&) = delete;
    CollisionManager& operator=(const CollisionManager&) = delete;

public:
    /// <summary> Gets the instance of the collision manager </summary>
    static CollisionManager& GetInstance()
    {
        static CollisionManager instance;
        return instance;
    }

    /// <summary> Checks collision on active gameobjects </summary>
    void CheckCollisions() const;

    /// <summary> Adds a game object to the manager </summary>
    void AddObject(Gameobject* object);

    /// <summary> Removes a game object from the manager </summary>
    void RemoveObject(Gameobject* object);
};

#endif //COLLISIONMANAGER_H