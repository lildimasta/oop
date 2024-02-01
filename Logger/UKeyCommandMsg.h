#pragma once

#include "IMessage.h"

class UKeyCommandMsg : public IMessage{
private:
    char key;
public:
    UKeyCommandMsg(char key);
    std::ostream& printInfo(std::ostream& os) const override;
};