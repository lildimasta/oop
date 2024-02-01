#ifndef TERMINALCOMMAND_H
#define TERMINALCOMMAND_H

#include "CommandHandler.h"

class TerminalCommand : public ICommandHandler{
public:
    Command handleCommand();
};

#endif