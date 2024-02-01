#ifndef CHANGECOORDSEVENT_H
#define CHANGECOORDSEVENT_H

#include "eventInterface.h"
#include "../Manager/gameManager.h"
#include "../Field/GameField.h"

#define CHANGE_X_Y 2

class ChangeCoordsEvent : public EventInterface{
private:
    GameField& field;
    gameManager& gameM;
    bool OpenNewCells;
    int lineWidth;
public:
    ChangeCoordsEvent(gameManager& gameM, GameField& field, bool OpenNewCells = true);
    void trigger();
};

#endif