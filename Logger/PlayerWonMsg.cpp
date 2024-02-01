#include "PlayerWonMsg.h"

PlayerWonMsg::PlayerWonMsg(int health, int score) : health(health), score(score){}

std::ostream& PlayerWonMsg::printInfo(std::ostream& os) const {
    return os << "Player won : health - " << health << ", score - " << score << "\n"; 
}