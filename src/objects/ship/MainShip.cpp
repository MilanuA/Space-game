#include "MainShip.h"
#include <cmath>
#include <iostream>
#include <raymath.h>

#include "../../gameobject/components/ColliderComponent.h"
#include "../../gameobject/components/SpriteRendererComponent.h"

void MainShip::Init()
{
    this->AddComponent<SpriteRendererComponent>().SetTexture( LoadTexture("../resources/ships/mainship.png"));
    this->AddComponent<ColliderComponent>();

    transform.SetPosition(Vector2(400,300));
}

void MainShip::UpdatePosition()
{
    Vector2 mousePosition = GetMousePosition();

    Vector2 direction = Vector2Subtract(mousePosition, transform.GetPosition());
    Vector2 newPosition = Vector2Add(transform.GetPosition(), Vector2Scale(direction, 1.0f / dragSpeed));

    transform.SetPosition(newPosition);

    const float x = static_cast<float>(GetMouseX()) - transform.GetPosition().x;
    const float y = static_cast<float>(GetMouseY()) - transform.GetPosition().y;
    transform.SetRotation(std::atan2(y, x) * RAD2DEG + 90);
}

bool MainShip::IsMovingFast() const
{
    Vector2 mousePosition = {static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())};
    Vector2 delta = Vector2Subtract(transform.GetPosition(), mousePosition);
    float speed = Vector2Length(delta);

    return speed > 200.0f;
}

void MainShip::Update(float deltaTime)
{
    Gameobject::Update(deltaTime);

    UpdatePosition();
}

void MainShip::Destroy()
{
    Gameobject::Destroy();
}

void MainShip::OnTriggerEnter2D(Gameobject *other)
{
    Gameobject::OnTriggerEnter2D(other);
}

void MainShip::Draw() const
{
    Gameobject::Draw();
}

MainShip::~MainShip()
{

}

