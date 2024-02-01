#include "Cell.h"

Cell::Cell(bool isPassable) : passable(isPassable), event(nullptr){}

Cell::~Cell(){
    if (event != nullptr) {
        delete event;
    }
}

bool Cell::isPassable() {
    return passable;
}

void Cell::setPassable(bool value){
    passable = value;
}

void Cell::setEvent(EventInterface* newEvent){
    if(event == nullptr){
        event = newEvent;
    }
}

EventInterface* Cell::getEvent(){
    return event;
}