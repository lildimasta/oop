#ifndef PRINTFIELD_H
#define PRINTFIELD_H

#include "../Field/GameField.h"
#include "EventSymbolSelector.h"

class PrintField{
private:
    GameField& field;
    EventSymbolSelector eventSeleсtor;
public:
    PrintField(GameField& gameField);
    void print(int x, int y);
};

#endif