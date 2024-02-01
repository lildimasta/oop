#include <iostream>
#include "gameManager.h"

gameManager::gameManager(Player& playerRef, GameField& fieldRef) : player(playerRef), field(fieldRef), x(START_POINT_X_Y), y(START_POINT_X_Y){}

void gameManager::movePlayer(Direction direction) {
    int newX = x;
    int newY = y;

    switch (direction) {
        case Direction::UP:
            newY++;
            break;
        case Direction::DOWN:
            newY--;
            break;
        case Direction::LEFT:
            newX--;
            break;
        case Direction::RIGHT:
            newX++;
            break;
    }

    if (newX >= MIN_X_Y && newX < field.getWidth() && newY >= MIN_X_Y && newY < field.getHeight()) {
        if (field.getCell(newX, newY).isPassable()) {
            x = newX;
            y = newY;
            EventInterface* event = field.getCell(getX(), getY()).getEvent();
            if(event){
                event->trigger();
            }
        }
        else{
            std::cout << "Клетка не проходима\n";
        }
    }
}

void gameManager::increaseScore(int points) {
    int currentScore = player.getScore() + points;
    player.setScore(currentScore);
}

void gameManager::decreaseHealth(int damage) {
    int currentHealth = player.getHealth() - damage;
    player.setHealth(currentHealth);
}

void gameManager::increaseHealth(int heal) {
    int currentHealth = player.getHealth() + heal;
    player.setHealth(currentHealth);
}

int gameManager::getX(){
    return x;
}

int gameManager::getY(){
    return y;
}

void gameManager::setX(int newX){
    if(newX >= MIN_X_Y && newX <= MAX_X_Y){
        x = newX;
    }else{
        std::cout<< "Неверные координаты\n";
    }
}

void gameManager::setY(int newY){
    if(newY >= MIN_X_Y && newY <= MAX_X_Y){
        y = newY;
    }else{
        std::cout<< "Неверные координаты\n";
    }
}