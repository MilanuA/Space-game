#include "CollisionManager.h"


// even though this Brute force collision detection is not efficient
// (we are probably talking about O(n^2) complexity)
// it's good enough for this purpose, because I won't use more than 50 objects
void CollisionManager::CheckCollisions() const
{

    for (size_t i = 0; i < objects.size(); ++i)
    {
        Rectangle const currentRect = objects[i]->GetBoundingBox();

        for (size_t j = i + 1; j < objects.size(); ++j)
        {
            if (CheckCollisionRecs(currentRect, objects[j]->GetBoundingBox()))
            {
                objects[i]->OnTriggerEnter2D(objects[j]);
                objects[j]->OnTriggerEnter2D(objects[i]);
            }
        }
    }
}

void CollisionManager::AddObject(Gameobject *object)
{
    objects.push_back(object);
}

void CollisionManager::RemoveObject(Gameobject *object)
{
    std::erase(objects, object);
}
