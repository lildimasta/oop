#include <iostream>

#include "PositiveEvent.h"

PositiveEffectEvent::PositiveEffectEvent(gameManager& gameM) : gameM(gameM){}

void PositiveEffectEvent::trigger(){
    gameM.increaseHealth(INCREASE_POINTS_HP);
    gameM.increaseScore(INCREASE_POINTS_HP);


}