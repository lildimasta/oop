#ifndef NEGATIVEEVENT_H
#define NEGATIVEEVENT_H

#include "eventInterface.h"
#include "../Manager/gameManager.h"

#define DECREASE_HP 3

class NegativeEvent : public EventInterface{
private:
    gameManager& gameM;
public:
    NegativeEvent(gameManager& gameM);
    void trigger();
};

#endif