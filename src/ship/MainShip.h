#ifndef MAINSHIP_H
#define MAINSHIP_H
#include <raylib.h>


class MainShip
{
    Vector2 shipPosition = {};
    Texture2D shipTexture = {};

    float dragSpeed = 40.0f;
    float shipRotation = 0.0f;

public:
    void UpdatePosition(Vector2 mousePosition);
    void DrawShip() const;
    void Init();
    Vector2 GetPosition() const { return shipPosition; }

    /// <summary> Checks if the ship is moving fast </summary>
    /// <returns> true if the ship is moving fast, false otherwise </returns>
    bool IsMovingFast() const;
    ~MainShip();
};



#endif //MAINSHIP_H
