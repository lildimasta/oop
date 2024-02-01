#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

enum Command { UP, DOWN, LEFT, RIGHT, QUIT, INFO, UNKNOWN };

class ICommandHandler {
public:
    virtual Command handleCommand() = 0;
    virtual ~ICommandHandler() {}
};

#endif