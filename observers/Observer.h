#pragma once

#include "IObserver.h"
#include "../Manager/gameManager.h"

class Observer: public IObserver{
private:
    gameManager& gameM;
    int coordX, coordY;
public:
    Observer(gameManager& gameM);
    bool Update();
};