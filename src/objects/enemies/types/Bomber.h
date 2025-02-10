#ifndef BOMBER_H
#define BOMBER_H
#include "../EnemyBase.h"

class Bomber : EnemyBase
{
    void Attack() override;
    void Movement() override;

public:
    Bomber(float maxHealth, const Texture2D &shipTexture, const Texture2D &explosionTexture) : EnemyBase(maxHealth,shipTexture, explosionTexture, EnemiesEnum::Bomber) {}
};



#endif //BOMBER_H
