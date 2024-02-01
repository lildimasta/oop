#pragma once

#include "../Player/Player.h"
#include "IObserver.h"

class PlayerObserver : public IObserver {
private:
    Player& player;
    int LastHealth, LastScore;
public:
    PlayerObserver(Player& player);
    bool Update();
};