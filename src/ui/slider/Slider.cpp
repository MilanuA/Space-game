#include "Slider.h"

#include "../../Helper.h"

Slider::Slider(const Texture2D &bgTex, const Texture2D &fillTex, Vector2 pos, float maxVal, float scaleSlider, float fillOffX) : backgroundTexture(bgTex),
fillTexture(fillTex),
position(pos),
maxValue(maxVal),
currentValue(maxVal), scale(scaleSlider), fillOffsetX(fillOffX) {
}

void Slider::UpdateValue(float value)
{
    currentValue = value;

    if (currentValue < 0) currentValue = 0;

    if (currentValue > maxValue) currentValue = maxValue;
}

void Slider::Render() const
{
    DrawTextureEx(backgroundTexture, position, 0.0f, scale, WHITE);

    const float fillWidth = static_cast<float>(fillTexture.width) * (currentValue / maxValue);
    const Rectangle sourceRect = {0.0f, 0.0f, fillWidth, static_cast<float>(fillTexture.height)};
    const Rectangle destRect = {position.x + (fillOffsetX * scale), position.y, fillWidth * scale, static_cast<float>(fillTexture.height) * scale};

    DrawTexturePro(fillTexture, sourceRect, destRect, {0.0f, 0.0f}, 0.0f, WHITE);
}