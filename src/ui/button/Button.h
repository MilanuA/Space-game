#ifndef BUTTON_H
#define BUTTON_H
#include <raylib.h>


class Button
{
public:
    Button(const char* imagePath, Vector2 imagePosition, float scale);
    ~Button();
    void Draw();
    void SetPosition(Vector2 newPosition);
    bool IsPressed(Vector2 mousePos, bool mousePressed);

private:
    Texture2D texture;
    Vector2 position;

    bool wasHoveredBefore = false;

    Color normalColor = WHITE;
    Color darkenColor = { 50, 50, 50, 255 };

    void Hovered();
    void UnHovered();
};



#endif //BUTTON_H
