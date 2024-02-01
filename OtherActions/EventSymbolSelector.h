#ifndef EVENTSYMBOLSELECTOR_H
#define EVENTSYMBOLSELECTOR_H

#include "../Event/eventInterface.h"
#include "../Event/PositiveEvent.h"
#include "../Event/NegativeEvent.h"
#include "../Event/ChangeCoordsEvent.h"

class EventSymbolSelector {
public:
    const char* getSymbolForEvent(EventInterface* event);
};

#endif