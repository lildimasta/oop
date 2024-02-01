#ifndef PLAYER_H
#define PLAYER_H

#define MAX_HEALTH 10
#define MIN_HEALTH 0
#define START_SCORE 0

class Player {
private:
    int health;
    int score;

public:
    Player();
    Player(int health, int score);
    int getHealth();
    int getScore();
    void setHealth(int newHealth);
    void setScore(int newScore);
};

#endif