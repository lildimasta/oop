#include <iostream>

#include "PrintField.h"

PrintField::PrintField(GameField &gameField) : field(gameField){}

void PrintField::print(int x, int y){
    int height = field.getHeight();
    int width = field.getWidth();
    int exitX = field.getExitX();
    int exitY = field.getExitY();
    
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            if (j == x && i == y) {
                std::cout << "P ";
            } else if (j == exitX && i == exitY) {
                std::cout << "E ";
            } else {
                EventInterface* event = field.getCell(j, i).getEvent();
                if(event != nullptr){
                    std::cout << (field.getCell(j, i).isPassable() ? eventSeleсtor.getSymbolForEvent(event) : "# ");
                }else{
                    std::cout << (field.getCell(j, i).isPassable() ? ". " : "# ");
                }
            }
        }
        std::cout << "\n";
    }
}