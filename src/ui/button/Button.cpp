#include "Button.h"

#include <iostream>

Button::Button(const char *imagePath, Vector2 imagePosition, float scale)
{
    Image image = LoadImage(imagePath);

    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    position = imagePosition;
    scaleFactor = scale;
}

Button::~Button()
{
    UnloadTexture(texture);
}

void Button::Draw()
{
    Rectangle sourceRec = {0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    Rectangle destRec = {position.x, position.y, texture.width * scaleFactor, texture.height * scaleFactor};
    Vector2 origin = {0.0f, 0.0f};

    DrawTexturePro(texture, sourceRec, destRec, origin, 0.0f, (wasHoveredBefore ? darkenColor : normalColor));
}

void Button::SetPosition(Vector2 newPosition)
{
    position = newPosition;
}

bool Button::IsPressed(Vector2 mousePos, bool mousePressed)
{
    Rectangle rect = {position.x, position.y, texture.width * scaleFactor, texture.height * scaleFactor};
    bool isHovered = CheckCollisionPointRec(mousePos, rect);

    if (!isHovered && wasHoveredBefore)
    {
        UnHovered();
        wasHoveredBefore = false;
    }
    else if (isHovered && !wasHoveredBefore)
    {
        Hovered();
        wasHoveredBefore = true;
    }

    return isHovered && mousePressed;
}

void Button::Hovered()
{
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
}

void Button::UnHovered()
{
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

