#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include "CommandHandler.h"

class CommandProcessor {
private:
    ICommandHandler* handler;

public:
    CommandProcessor(ICommandHandler* handler);
    Command processInput();
    ~CommandProcessor();
};

#endif