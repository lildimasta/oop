#include "UKeyCommandMsg.h"

UKeyCommandMsg::UKeyCommandMsg(char key) : key(key){}

std::ostream& UKeyCommandMsg::printInfo(std::ostream& os) const {
    return os << "Unknown key pressed - " << key << "\n";
}