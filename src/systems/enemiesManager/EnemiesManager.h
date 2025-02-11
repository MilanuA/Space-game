#ifndef ENEMIESMANAGER_H
#define ENEMIESMANAGER_H
#include "../../objects/enemies/EnemiesEnum.h"
#include "../../objects/enemies/EnemyBase.h"

constexpr float BOMBER_MAX_HEALTH = 150.0f;
constexpr float FIGHTER_MAX_HEALTH = 50.0f;
constexpr float SCOUT_MAX_HEALTH = 100.0f;

class EnemiesManager
{
    std::vector<std::unique_ptr<EnemyBase>> enemies;
    std::vector<EnemyBase*> newly_spawned_enemies;

public:
    void SpawnEnemy(EnemiesEnum type);
    void UpdateEnemies();
};



#endif //ENEMIESMANAGER_H
