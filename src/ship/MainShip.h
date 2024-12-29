#ifndef MAINSHIP_H
#define MAINSHIP_H
#include <raylib.h>


class MainShip
{
    Vector2 shipPosition = {};
    Texture2D shipTexture = {};

    float dragSpeed = 40.0f;


public:
    void UpdatePosition(Vector2 mousePosition);
    void DrawShip() const;
    void Init();
    ~MainShip();
};



#endif //MAINSHIP_H
