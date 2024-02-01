#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Cell.h"

#define MAX_WIDTH 15
#define MAX_HEIGHT 15
#define MIN_WIDTH_HEIGHT 5
#define ENTRANCE 0

class GameField{
private:
    Cell** cells;
    int width;
    int height;
    int entranceX;
    int entranceY;
    int exitX;
    int exitY;

public:
    GameField();
    GameField(int w, int h);

    GameField(const GameField& other);
    GameField& operator=(const GameField& other);

    GameField(GameField&& other);
    GameField& operator=(GameField&& other);

    ~GameField();

    Cell& getCell(int x, int y);
    int getWidth();
    int getHeight();
    int getEntranceX();
    int getEntranceY();
    int getExitX();
    int getExitY();
    void setEntrance(int x, int y);
    void setExit(int x, int y);
};

#endif