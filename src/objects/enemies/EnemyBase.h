#ifndef ENEMYBASE_H
#define ENEMYBASE_H
#include "EnemiesEnum.h"
#include "../../gameobject/Gameobject.h"
#include "../../systems/health/IHealth.h"

class EnemyBase : public IHealth, public Gameobject
{
    EnemiesEnum type;
    Texture2D shipTexture;
    Texture2D explosionTexture;

public:
    explicit EnemyBase(float maxHealth, const Texture2D &shipTexture, const Texture2D &explosionTexture, EnemiesEnum enemyType): IHealth(maxHealth), Gameobject(GameobjectsEnum::Enemy),
                                                                type(enemyType), shipTexture(shipTexture), explosionTexture(explosionTexture) {
    }

    virtual void Attack() {}
    virtual void Movement() {}
    virtual void Update() {}

    void TakeDamage(int damage) override;
    void Heal(int amount) override;
    void Death() override;

    virtual ~EnemyBase() = default;
};



#endif //ENEMYBASE_H
