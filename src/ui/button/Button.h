#ifndef BUTTON_H
#define BUTTON_H
#include <raylib.h>

class Button
{
    Texture2D texture;
    Vector2 position;

    bool wasHoveredBefore = false;
    float scaleFactor = 1.0f;

    Color normalColor = WHITE;
    Color darkenColor = { 50, 50, 50, 255 };

    void Hovered();
    void UnHovered();

public:
    Button(const char* imagePath, Vector2 imagePosition, float scale);
    ~Button();
    void Draw();
    void SetPosition(Vector2 newPosition);

    /// <returns>The size of the button</returns>
    Vector2 Size() const { return {texture.width * scaleFactor, texture.height * scaleFactor}; }
    bool IsPressed(Vector2 mousePos, bool mousePressed);


};



#endif //BUTTON_H
