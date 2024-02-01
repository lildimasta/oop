#pragma once

#include "IMessage.h"

class NewGameMsg : public IMessage {
private:
    bool newGame;
public:
    NewGameMsg(bool newgame);
    std::ostream& printInfo(std::ostream& os) const override;
};