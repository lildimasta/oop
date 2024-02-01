#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Game.h"

class Controller {
public:
    void ProcessComands(gameManager& gameM, Command cmd);
};

#endif