#pragma once

#include "ConsoleLog.h"
#include "IMessage.h"
#include "FileLog.h"
#include <vector>


class Logger{
private:
    std::vector<MessageEmitter*> emitters;
    static Logger* instance;
    Logger() = default;
public:
    static Logger* getInstance();
    static void destroy();

    void addStream(bool console, bool file);
    void logMessage(const IMessage& message);
    ~Logger();
};