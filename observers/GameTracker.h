#pragma once

#include "../Field/GameField.h"
#include "../Manager/gameManager.h"
#include "../OtherActions/PrintField.h"
#include "../Player/Player.h"
#include "Observer.h"
#include "PlayerObserver.h"
#include "../Logger/PlayerWonMsg.h"
#include "../Logger/PlayerLostMsg.h"
#include "../Logger/Logger.h"

#include <iostream>

class GameTracker{
private:
    GameField& field;
    gameManager& gameM;
    Player& player;
    PrintField ConsoleField;
    Observer obs;
    PlayerObserver pl;
    void ConsolePrint();
public:
    GameTracker(Player& player, GameField& field, gameManager& gameM, Observer obs, PlayerObserver pl);
    void Track();
    bool CheckState();
};