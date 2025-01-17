#include "Animation.h"

#include "../../Helper.h"

Animation::Animation(const Texture2D &texture, int frameCount, float frameDuration)
    : texture(texture), frameCount(frameCount), frameDuration(frameDuration), position({0.0f, 0.0f})
{
}

void Animation::Play(Vector2 position, float scale, float rotation)
{
    this->position = position;
    this->scale = scale;
    this->rotation = rotation;
    this->elapsedTime = 0.0f;
    this->currentFrame = 0;
    this->playing = true;
}

void Animation::Update(float deltaTime)
{
    if (!playing) return;

    elapsedTime += deltaTime;
    if (elapsedTime >= frameDuration)
    {
        elapsedTime -= frameDuration;
        currentFrame++;

        if (currentFrame >= frameCount)
        {
            currentFrame = 0;
            playing = false;
        }
    }
}


void Animation::Draw() const
{
    if (!playing) return;

    int frameWidth = texture.width / frameCount;
    Rectangle source = { static_cast<float>(currentFrame * frameWidth), 0.0f, static_cast<float>(frameWidth), static_cast<float>(texture.height) };

    Rectangle dest = { position.x, position.y, frameWidth * scale, texture.height * scale };

    Vector2 origin = { static_cast<float>(frameWidth * scale / 2.0f), static_cast<float>(texture.height * scale / 2.0f) };

    DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
}


void Animation::Stop()
{
    playing = false;
}