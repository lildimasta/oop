#pragma once

#include "MessageEmitter.h"
#include <fstream>

class FileLog : public MessageEmitter {
private:
    std::ofstream file;
public:
    FileLog(const std::string& name);
    void output(const IMessage& msg) override;
    ~FileLog() override;
};