#pragma once

#include "IMessage.h"

class PlayerWonMsg : public IMessage {
private:
    int score, health;
public:
    PlayerWonMsg(int health, int score);
    std::ostream& printInfo(std::ostream& os) const override;
};