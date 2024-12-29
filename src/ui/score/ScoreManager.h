#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

class ScoreManager
{
    int currentScore = 0;
    int scorePerSecond = 1;

public:
    void UpdateScorePerSecond();
    void Draw() const;

};



#endif //SCOREMANAGER_H
