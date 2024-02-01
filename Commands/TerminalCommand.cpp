#include <iostream>
#include "TerminalCommand.h"


Command TerminalCommand::handleCommand() {
    char input;
    std::cin >> input;
    switch (input) {
        case 'w': return Command::UP;
        case 'a': return Command::LEFT;
        case 's': return Command::DOWN;
        case 'd': return Command::RIGHT;
        case 'q': return Command::QUIT;
        case 'i': return Command::INFO;
        default: return Command::UNKNOWN;
    }
    return Command::UNKNOWN;
}