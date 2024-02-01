#include <iostream>

#include "controller.h"

void Controller::ProcessComands(gameManager& gameM, Command cmd) {

    switch (cmd) {
        case Command::UP:
            gameM.movePlayer(Direction::UP);
            std::cout << "\n";
            break;

        case Command::LEFT:
            gameM.movePlayer(Direction::LEFT);
            std::cout << "\n";
            break;

        case Command::DOWN:
            gameM.movePlayer(Direction::DOWN);
            std::cout << "\n";
            break;

        case Command::RIGHT:
            gameM.movePlayer(Direction::RIGHT);
            std::cout << "\n";
            break;

        case Command::QUIT:
            return;

        case Command::INFO:
            std::cout << "X = " << gameM.getX() << " Y = " << gameM.getY() << "\n";
            break;

        case Command::UNKNOWN:
            std::cout << "Введена неверная комманда\n";
            break;
    }
}