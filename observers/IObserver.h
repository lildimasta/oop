#pragma once

#include <string>

class IObserver {
public:
    virtual bool Update() = 0;
};