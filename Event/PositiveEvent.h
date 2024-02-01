#ifndef POSITIVEEVENT_H
#define POSITIVEEVENT_H

#include "eventInterface.h"
#include "../Manager/gameManager.h"

#define INCREASE_POINTS_HP 2

class PositiveEffectEvent : public EventInterface{
private:
    gameManager& gameM;
public:
    PositiveEffectEvent(gameManager& gameM);
    void trigger();
};

#endif