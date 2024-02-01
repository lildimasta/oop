#include "KeyCommandMsg.h"

KeyCommandMsg::KeyCommandMsg(char key, Command cmd) : key(key), cmd(cmd){}

std::ostream& KeyCommandMsg::printInfo(std::ostream& os) const {
    return os << "Key - " << key << " Command - " << CommandToString(cmd) << "\n";
}

std::string KeyCommandMsg::CommandToString(Command cmd) const {
    switch(cmd){
        case LEFT:
            return "LEFT";
        case RIGHT:
            return "RIGHT";
        case UP:
            return "UP";
        case DOWN:
            return "DOWN";
        case QUIT:
            return "QUIT";
        case INFO:
            return "INFO";
        default:
            return "UNKNOWN";
    }
}