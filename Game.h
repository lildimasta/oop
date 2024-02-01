#ifndef GAMESTART_H
#define GAMESTART_H

#include "./Manager/gameManager.h"
#include "./OtherActions/GameLevel.h"
#include "./Event/NegativeEvent.h"
#include "./Event/ChangeCoordsEvent.h"
#include "./Event/PositiveEvent.h"
#include "./Commands/TerminalCommand.h"
#include "./Commands/FileCommand.h"
#include "./Commands/CommandProcessor.h"
#include "./observers/Observer.h"
#include "./observers/GameTracker.h"
#include "./Logger/NewGameMsg.h"


class Game{
public:
    void StartGame();
};

#endif