#include <iostream>

#include "NegativeEvent.h"

NegativeEvent::NegativeEvent(gameManager& gameM) : gameM(gameM){}

void NegativeEvent::trigger(){
    gameM.decreaseHealth(DECREASE_HP);
    
}