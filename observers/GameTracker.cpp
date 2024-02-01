#include "GameTracker.h"

GameTracker::GameTracker(Player& player, GameField& field, gameManager& gameM, Observer obs, PlayerObserver pl) : player(player), field(field), gameM(gameM), obs(obs), pl(pl), ConsoleField(field){}

void GameTracker::Track(){
    if(obs.Update() || pl.Update()){
        ConsolePrint();
    }
}

void GameTracker::ConsolePrint(){
    ConsoleField.print(gameM.getX(), gameM.getY());
}

bool GameTracker::CheckState(){
    Logger* logger = Logger::getInstance();

    if(gameM.getX() == field.getExitX() && gameM.getY() == field.getExitY()){
        std::cout << "Вы выиграли!\n";

        logger->logMessage(PlayerWonMsg(player.getHealth(), player.getScore()));

        return true;

    }else if (player.getHealth() == 0){
        std::cout << "Вы проиграли!\n";

        logger->logMessage(PlayerLostMsg(gameM.getX(), gameM.getY()));

        return true;
    }
    return false;
}