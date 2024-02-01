#include "GameLevel.h"

#include <iostream>

GameLevel::GameLevel() : input(), field(){}

GameField GameLevel::generate1() {
    initialField = input.chooseField();
    GameField field(initialField, initialField);
    field.setEntrance(0,0);
    switch(initialField) {
        case 5:
            field.getCell(1, 1).setPassable(false);
            field.getCell(2, 1).setPassable(false);
            field.getCell(3, 1).setPassable(false);
            field.getCell(3, 3).setPassable(false);
            field.getCell(2, 3).setPassable(false);
            field.getCell(1, 3).setPassable(false);
            break;

        case 10:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (rand() % 2 == 0) {
                        field.getCell(i, j).setPassable(false);
                    }
                }
            }
            field.getCell(1, 3).setPassable(false);
            field.getCell(1,0).setPassable(true);
            field.getCell(4,4).setPassable(true);
            field.getCell(7,6).setPassable(true);
            field.getCell(8,8).setPassable(true);
            field.getCell(9, 9).setPassable(true);
            field.getCell(2, 4).setPassable(true);
            field.getCell(1, 2).setPassable(true);
            field.getCell(0,0).setPassable(true);
            break;

        case 15:
            for (int i = 0; i < 15; ++i) {
                for (int j = 0; j < 15; ++j) {
                    if (rand() % 2 == 0) {
                        field.getCell(i, j).setPassable(false);
                    }
                }
            }
            field.getCell(1,0).setPassable(true);
            field.getCell(6,0).setPassable(true);
            field.getCell(13,13).setPassable(true);
            field.getCell(0,1).setPassable(true);
            field.getCell(4,4).setPassable(true);
            field.getCell(6,3).setPassable(true);
            field.getCell(14, 14).setPassable(true);
            field.getCell(2, 3).setPassable(true);
            field.getCell(0,0).setPassable(true);
            break;

        default:
            break;
    }
    return field;
}