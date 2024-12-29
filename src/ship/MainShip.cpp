#include "MainShip.h"

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
    DrawTexture(shipTexture, shipPosition.x - shipTexture.width / 2, shipPosition.y - shipTexture.height / 2, WHITE);
}

MainShip::~MainShip()
{
    UnloadTexture(shipTexture);

}
