#include "PlayerLostMsg.h"

PlayerLostMsg::PlayerLostMsg(int x, int y) : x(x), y(y){}

std::ostream& PlayerLostMsg::printInfo(std::ostream& os) const {
    return os << "Player lost : x - " << x << ", y - " << y << "\n"; 
}