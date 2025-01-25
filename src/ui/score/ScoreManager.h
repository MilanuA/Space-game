#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

constexpr int SCORE_PER_SECOND = 1;
class ScoreManager
{
    int currentScore = 0;

public:
    void UpdateScorePerSecond();
    void Draw() const;
    void UpdateScore(int score);
    [[nodiscard]] int GetCurrentScore() const { return currentScore; }
};



#endif //SCOREMANAGER_H
