#include "PlayerObserver.h"

PlayerObserver::PlayerObserver(Player& player) : player(player){
    LastHealth = player.getHealth();
    LastScore = player.getScore();
}

bool PlayerObserver::Update(){
    if (LastHealth != player.getHealth() || LastScore != player.getScore()){
        LastHealth = player.getHealth();
        LastScore = player.getScore();
        return true;
    }
    return false;
}