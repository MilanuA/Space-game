#ifndef POOLABLEOBJECT_H
#define POOLABLEOBJECT_H


class PoolableObject
{
protected:
    bool isActive = false;

public:
    /// <summary> Virtual destructor to ensure proper cleanup </summary>
    virtual ~PoolableObject() = default;

    /// <summary> Sets the object as active </summary>
    void Activate() { isActive = true; }

    /// <summary> Sets the object as inactive </summary>
    void Deactivate() { isActive = false; }

    /// <summary> Checks if the object is active </summary>
    /// <returns> true if the object is active, false otherwise </returns>
    [[nodiscard]] bool IsActive() const { return isActive; }
};



#endif //POOLABLEOBJECT_H