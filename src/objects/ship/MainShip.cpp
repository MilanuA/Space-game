#include "MainShip.h"
#include <cmath>
#include <iostream>
#include <raymath.h>

#include "../../Helper.h"
#include "../../gameobject/components/ColliderComponent.h"
#include "../../gameobject/components/SpriteRendererComponent.h"
#include "../../scenes/SceneManager.h"
#include "../../systems/collisionManager/CollisionManager.h"

void MainShip::Init(SceneManager* scene_manager)
{
    this->AddComponent<SpriteRendererComponent>().SetTexture( LoadTexture("../resources/ships/mainship.png"));
    this->AddComponent<ColliderComponent>().SetCustomCollisionDecreaser(1.2f);

    transform.SetPosition(SPAWN_POSITION);
    transform.SetScale(Vector2(SHIP_SPRITE_SCALE, SHIP_SPRITE_SCALE));

    playerHealthBar->SetMaxHealth(maxHealth);
    CollisionManager::GetInstance().AddObject(this);
    this->scene_manager = scene_manager;

    invulnerabilityTimer = 0.0f;
    flashTimer = 0.0f;
}

void MainShip::Update(float deltaTime)
{
    Gameobject::Update(deltaTime);

    UpdatePosition();

    if (state != ShipState::Invulnerable) return;

    UpdateInvulnerability(deltaTime);
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

void MainShip::Destroy()
{
    Gameobject::Destroy();
}

void MainShip::OnTriggerEnter2D(Gameobject *other)
{
    if (state == ShipState::Invulnerable) return;

    if (other->GetTag() == GameobjectsEnum::Asteroid)
    {
        TakeDamage(ASTEROID_DAMAGE);
    }
}

void MainShip::Draw() const
{
    if (!isSpriteVisible)  return;

    Gameobject::Draw();
}

void MainShip::TakeDamage(int damage)
{
    if (state == ShipState::Invulnerable) return;

    playerHealthBar->DecreaseHealth(damage);
    EnterInvulnerableState();
    currentHealth -= damage;

    if (currentHealth > 0) return;

    Death();
}

void MainShip::Heal(int amount)
{

}

void MainShip::Death()
{
    Destroy();

    scene_manager->SetCurrentScene(SceneType::DEATH);
}


void MainShip::UpdateInvulnerability(float deltaTime)
{
    invulnerabilityTimer -= deltaTime;
    flashTimer -= deltaTime;

    if (flashTimer <= 0.0f)
    {
        isSpriteVisible = !isSpriteVisible;
        flashTimer = FLASH_INTERVAL;
    }

    if (invulnerabilityTimer <= 0.0f)
    {
        state = ShipState::Normal;
        isSpriteVisible = true;
        CollisionManager::GetInstance().AddObject(this);
    }
}

void MainShip::EnterInvulnerableState()
{
    state = ShipState::Invulnerable;
    invulnerabilityTimer = INVULNERABILITY_DURATION;
    flashTimer = FLASH_INTERVAL;
    CollisionManager::GetInstance().RemoveObject(this);
}

MainShip::~MainShip()
{

}

