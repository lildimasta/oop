#pragma once

#include <iostream>

class IMessage {
public:
    virtual std::ostream& printInfo(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const IMessage& msg);
};