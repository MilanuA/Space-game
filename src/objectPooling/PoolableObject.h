#ifndef POOLABLEOBJECT_H
#define POOLABLEOBJECT_H



class PoolableObject
{
protected:
    bool isActive = false;

public:
    /// <summary> Virtual destructor to ensure proper cleanup </summary>
    virtual ~PoolableObject() = default;

    /// <summary> Updates the object logic </summary>
    /// <param name="deltaTime"> time since last frame </param>
    virtual void Update(float deltaTime) = 0;

    /// <summary> Draws the object </summary>
    virtual void Draw() const = 0;

    /// <summary> Sets the object as active </summary>
    void Activate() { isActive = true; }

    /// <summary> Sets the object as inactive </summary>
    void Deactivate() { isActive = false; }

    /// <summary> Checks if the object is active </summary>
    /// <returns> true if the object is active, false otherwise </returns>
    bool IsActive() const { return isActive; }
};



#endif //POOLABLEOBJECT_H