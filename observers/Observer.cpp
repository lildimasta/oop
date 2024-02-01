#include "Observer.h"
#include <iostream>

Observer::Observer(gameManager& gameM): gameM(gameM){
    coordX = gameM.getX();
    coordY = gameM.getY();
}

bool Observer::Update(){
    if(coordX != gameM.getX() || coordY != gameM.getY()){
        coordX = gameM.getX();
        coordY = gameM.getY();
        return true;
    }
    return false;
}
