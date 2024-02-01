#include "IMessage.h"

std::ostream& operator<<(std::ostream& os, const IMessage& msg) {
    return msg.printInfo(os);
}