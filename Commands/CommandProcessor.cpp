#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(ICommandHandler* handler) : handler(handler) {}

Command CommandProcessor::processInput() {
    return handler->handleCommand();
}

CommandProcessor::~CommandProcessor() {
    if(handler != nullptr){
        delete handler;
    }
}