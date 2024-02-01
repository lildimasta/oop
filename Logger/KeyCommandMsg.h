#pragma once

#include "IMessage.h"
#include "../Commands/CommandHandler.h"

class KeyCommandMsg : public IMessage {
private:
    char key;
    Command cmd;
public:
    KeyCommandMsg(char key, Command cmd);
    std::ostream& printInfo(std::ostream& os) const override;
    std::string CommandToString(Command cmd) const;
};