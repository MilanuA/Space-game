
#ifndef ANIMATION_H
#define ANIMATION_H
#include <raylib.h>

class Animation
{
    Texture2D texture = {};
    int frameCount = 1;
    float frameDuration = 0.1f;
    float elapsedTime = 0.0f;
    int currentFrame = 0;
    bool playing = false;

    Vector2 position = {0.0f, 0.0f};
    float scale = 1.0f;
    float rotation = 0.0f;

public:
    Animation(const Texture2D &texture, int frameCount, float frameDuration);

    void Play(Vector2 position, float scale = 1.0f, float rotation = 0.0f);
    void Update(float deltaTime);
    void Draw() const;

    [[nodiscard]] bool IsPlaying() const { return playing; }
    void Stop();
};

#endif //ANIMATION_H