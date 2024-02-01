#include "NewGameMsg.h"

NewGameMsg::NewGameMsg(bool newgame) : newGame(newgame){}

std::ostream& NewGameMsg::printInfo(std::ostream& os) const {
    if(newGame){
       return os << "New game started\n";
    }
    return os << "Game ended\n";
}