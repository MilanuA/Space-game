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
    float rotation = std::atan2(y, x) * RAD2DEG;

    Rectangle sourceRec = { 0, 0, (float)shipTexture.width, (float)shipTexture.height };
    Rectangle destRec = { shipPosition.x, shipPosition.y, (float)shipTexture.width, (float)shipTexture.height };
    Vector2 origin = { (float)shipTexture.width/2, (float)shipTexture.height/2 };

    DrawTexturePro(shipTexture, sourceRec, destRec, origin, rotation + 90, RAYWHITE);
}

MainShip::~MainShip()
{
    UnloadTexture(shipTexture);
}