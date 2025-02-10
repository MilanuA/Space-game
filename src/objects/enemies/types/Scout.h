#ifndef SCOUT_H
#define SCOUT_H
#include "../EnemyBase.h"

class Scout : public EnemyBase
{
    void Attack() override;
    void Movement() override;

public:
    Scout(float maxHealth, const Texture2D &shipTexture, const Texture2D &explosionTexture) : EnemyBase(maxHealth,shipTexture, explosionTexture, EnemiesEnum::Scout) {}
};



#endif //SCOUT_H
