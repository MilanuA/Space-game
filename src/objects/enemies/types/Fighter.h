#ifndef FIGHTER_H
#define FIGHTER_H
#include "../EnemyBase.h"

class Fighter : public EnemyBase
{
    void Attack() override;
    void Movement() override;
public:
    Fighter(float maxHealth, const Texture2D &shipTexture, const Texture2D &explosionTexture) : EnemyBase(maxHealth,shipTexture, explosionTexture, EnemiesEnum::Fighter) {}
};



#endif //FIGHTER_H
