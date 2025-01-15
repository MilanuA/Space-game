#include "HealthBar.h"

void HealthBar::SetMaxHealth(const float maxHealth)
{
    maxValue = maxHealth;
    currentValue = maxHealth;
}

void HealthBar::DecreaseHealth(float value)
{
    UpdateValue(currentValue - value);

    if (currentValue == 0)
    {

    }
}
