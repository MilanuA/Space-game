#include "MainShip.h"
#include <cmath>

void MainShip::Init()
{
    shipTexture = LoadTexture("../graphics/ships/mainship.png");
    shipPosition = {400, 300};
}

void MainShip::UpdatePosition(Vector2 mousePosition)
{
    shipPosition.x += (mousePosition.x - shipPosition.x) / dragSpeed;
    shipPosition.y += (mousePosition.y - shipPosition.y) / dragSpeed;
}

void MainShip::DrawShip() const
{
    float x = GetMouseX() - shipPosition.x, y = GetMouseY() - shipPosition.y;
    float rotation = std::atan2(x, y) * -57.29578f; // Convert radians to degrees

    DrawTexturePro(shipTexture, Rectangle{0, 0, (float)shipTexture.width, (float)shipTexture.height},
                           { shipPosition.x, shipPosition.y, (float)shipTexture.width, (float)shipTexture.height},
                           { (float)shipTexture.width/2, (float)shipTexture.height/2 }, rotation+180, RAYWHITE);
}

MainShip::~MainShip()
{
    UnloadTexture(shipTexture);
}
