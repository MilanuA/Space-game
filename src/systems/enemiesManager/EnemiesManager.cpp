#include "EnemiesManager.h"

#include "../../objects/enemies/types/Bomber.h"
#include "../../objects/enemies/types/Fighter.h"
#include "../../objects/enemies/types/Scout.h"

void EnemiesManager::SpawnEnemy(EnemiesEnum type)
{
    std::unique_ptr<EnemyBase> newEnemy;

    switch (type)
    {
        case EnemiesEnum::Bomber:
            newEnemy = std::make_unique<Bomber>(BOMBER_MAX_HEALTH, LoadTexture("../resources/ships/enemyShips/klaed/bomber/klaed_bomber.png"),
                LoadTexture("../resources/ships/enemyShips/klaed/bomber/klaed_bomber_destruction.png"));
        break;
        case EnemiesEnum::Fighter:
            newEnemy = std::make_unique<Fighter>(FIGHTER_MAX_HEALTH, LoadTexture("../resources/ships/enemyShips/klaed/fighter/klaed_fighter.png"),
                LoadTexture("../resources/ships/enemyShips/klaed/fighter/klaed_fighter_destruction.png"));
        break;
        case EnemiesEnum::Scout:
            newEnemy = std::make_unique<Scout>(SCOUT_MAX_HEALTH, LoadTexture("../resources/ships/enemyShips/klaed/scout/klaed_scout.png"),
                LoadTexture("../resources/ships/enemyShips/klaed/scout/klaed_scout_destruction.png"));
        break;
        default:
            return;
    }

    newly_spawned_enemies.push_back(newEnemy.get());
    enemies.push_back(std::move(newEnemy));
}

void EnemiesManager::UpdateEnemies()
{
    for (auto &enemy : enemies)
    {
        enemy->Update();
    }
}
