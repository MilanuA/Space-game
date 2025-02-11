#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <raylib.h>


class Helper
{
public:
    /// <summary> Checks if the position is outside the screen </summary>
    /// <param name="position"> The position to check </param>
    /// <param name="outOfScreenBuffer"> The buffer to check </param>
    /// <returns> true if the position is outside the screen, false otherwise </returns>
    static bool IsOutsideScreen(Vector2 position, float outOfScreenBuffer = 0.f)
    {
        return position.x < -outOfScreenBuffer || position.x > GetScreenWidth() + outOfScreenBuffer ||
               position.y < -outOfScreenBuffer || position.y > GetScreenHeight() + outOfScreenBuffer;
    }
};



#endif //HELPER_H
