#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include "inputManager.h"
#include "../Field/GameField.h"


class GameLevel{
private:
    GameField field;
    inputManager input;
    int initialField;
public:
    GameLevel();
    GameField generate1();
};

#endif