#include <iostream>
#include <thread>

#include "ChangeCoordsEvent.h"

ChangeCoordsEvent::ChangeCoordsEvent(gameManager& gameM, GameField& field, bool OpenNewCells) : gameM(gameM), field(field), OpenNewCells(OpenNewCells) {}


void ChangeCoordsEvent::trigger(){
    if(OpenNewCells == true){
        lineWidth = (field.getHeight() == 15) ? 3 : (field.getHeight() == 10) ? 2 : 1;
        for (int i = field.getHeight() - 1; i >= 0; i--) {
            for (int j = 0; j < field.getWidth(); j++) {
                 if (abs(i - j) < lineWidth){
                    field.getCell(i,j).setPassable(true);
                }
            }
        }
    }
}