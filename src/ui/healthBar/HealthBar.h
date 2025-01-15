#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "../slider/Slider.h"


class HealthBar : public Slider
{
public:
    HealthBar(const Texture2D &bgTex, const Texture2D &fillTex, const Vector2 &pos)
        : Slider(bgTex, fillTex, pos, 0, 4.0f, 14.f) {
    }

    void SetMaxHealth(const float maxHealth);
    void DecreaseHealth(float value);

};



#endif //HEALTHBAR_H
