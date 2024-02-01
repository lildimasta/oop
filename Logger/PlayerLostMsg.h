#pragma once

#include "IMessage.h"

class PlayerLostMsg : public IMessage {
private:
    int x, y;
public:
    PlayerLostMsg(int x, int y);
    std::ostream& printInfo(std::ostream& os) const override;
};