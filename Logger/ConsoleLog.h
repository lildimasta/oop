#pragma once

#include "MessageEmitter.h"

class ConsoleLog : public MessageEmitter {
public:
    void output(const IMessage& msg) override;
};