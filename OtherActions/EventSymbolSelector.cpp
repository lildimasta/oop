#include "EventSymbolSelector.h"

const char* EventSymbolSelector::getSymbolForEvent(EventInterface* event){
    if (dynamic_cast<PositiveEffectEvent*>(event) != nullptr) {
        return "Q ";
    } else if (dynamic_cast<NegativeEvent*>(event) != nullptr) {
        return "N ";
    } else if (dynamic_cast<ChangeCoordsEvent*>(event) != nullptr){
        return "C ";
    }
    return "? "; 
}