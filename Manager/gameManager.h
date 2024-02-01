#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../Player/Player.h"
#include "../Field/GameField.h"

#define START_POINT_X_Y 0
#define MAX_X_Y 15
#define MIN_X_Y 0

enum class Direction { UP, DOWN, LEFT, RIGHT };

class gameManager{
private:
    Player& player;
    GameField& field;
    int y;
    int x;
public:
    gameManager(Player& player, GameField& field);
    void movePlayer(Direction direction);
    void increaseScore(int points);
    void decreaseHealth(int damage);
    void increaseHealth(int heal);
    int getX();
    int getY();
    void setX(int newX);
    void setY(int newY);
};

#endif