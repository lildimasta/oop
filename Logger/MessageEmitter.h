#pragma once

#include "IMessage.h"

class MessageEmitter{
public:
    virtual void output(const IMessage& msg) = 0;
    virtual ~MessageEmitter() = default;
};