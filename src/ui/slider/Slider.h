#ifndef SLIDER_H
#define SLIDER_H
#include <raylib.h>

class Slider
{
protected:
    Texture2D backgroundTexture;
    Texture2D fillTexture;
    Vector2 position;
    float maxValue;
    float currentValue;
float scale = 1.0f;
    float fillOffsetX = 0.0f;

public:
    Slider(const Texture2D &bgTex, const Texture2D &fillTex, Vector2 pos, float maxVal, float scale = 1.0f, float fillOffsetX = 0.0f);
    void UpdateValue(float value);
    void Render() const;

    [[nodiscard]] float GetCurrentValue() const { return currentValue; }
};



#endif //SLIDER_H
