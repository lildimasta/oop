#include "Logger.h"

void Logger::addStream(bool console, bool file){
    if (console) {
        emitters.push_back(new ConsoleLog);
    }
    if (file) {
        emitters.push_back(new FileLog("Logger/log.txt"));
    }
}

void Logger::logMessage(const IMessage& message){
    for(MessageEmitter* emitter : emitters){
       emitter->output(message);
    }
}

Logger::~Logger(){
    for (auto& emitter : emitters) {
        delete emitter;
    }
    emitters.clear();
}

Logger* Logger::instance = nullptr;

Logger* Logger::getInstance(){
    if(!instance){
        instance = new Logger;
    }
    return instance;
}

void Logger::destroy(){
    delete instance;
}