#include "FileLog.h"

FileLog::FileLog(const std::string& name) : file(name){}

void FileLog::output(const IMessage& msg){
    if(file.is_open()){
        file << "[FILE] ";
        msg.printInfo(file);
    }
}

FileLog::~FileLog(){}