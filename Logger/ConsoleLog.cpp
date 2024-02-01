#include "ConsoleLog.h"

void ConsoleLog::output(const IMessage& msg){
    std::cout << "[CONSOLE] ";
    msg.printInfo(std::cout);
}
