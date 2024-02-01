#ifndef CELL_H
#define CELL_H

#include "../Event/eventInterface.h"


class Cell {
private:
    bool passable;
    EventInterface* event;
public:
    Cell(bool isPassable = true);
    ~Cell();
    bool isPassable();
    void setPassable(bool value);
    void setEvent(EventInterface* newEvent);
    EventInterface* getEvent();
};

#endif