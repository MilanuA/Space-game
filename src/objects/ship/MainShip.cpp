#include "MainShip.h"
#include <cmath>
#include <raymath.h>

void MainShip::Init()
{
    shipTexture = LoadTexture("../resources/ships/mainship.png");
    shipPosition = {400, 300};
}

void MainShip::UpdatePosition(Vector2 mousePosition)
{
    shipPosition.x += (mousePosition.x - shipPosition.x) / dragSpeed;
    shipPosition.y += (mousePosition.y - shipPosition.y) / dragSpeed;

    const float x = static_cast<float>(GetMouseX()) - shipPosition.x;
    const float y = static_cast<float>(GetMouseY()) - shipPosition.y;
    rotation = std::atan2(y, x) * RAD2DEG;
}

void MainShip::DrawShip() const
{


    Rectangle sourceRec = {0, 0, static_cast<float>(shipTexture.width), static_cast<float>(shipTexture.height)};
    Rectangle destRec = {shipPosition.x, shipPosition.y, static_cast<float>(shipTexture.width) * SHIP_SPRITE_SCALE, static_cast<float>(shipTexture.height) * SHIP_SPRITE_SCALE};
    Vector2 origin = {static_cast<float>(shipTexture.width) / 2, static_cast<float>(shipTexture.height) / 2};

    DrawTexturePro(shipTexture, sourceRec, destRec, origin, rotation + 90, RAYWHITE);
}

bool MainShip::IsMovingFast() const
{
    Vector2 mousePosition = {static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())};
    Vector2 delta = Vector2Subtract(shipPosition, mousePosition);
    float speed = Vector2Length(delta);
    return speed > 200.0f;
}

MainShip::~MainShip()
{
    UnloadTexture(shipTexture);
}
