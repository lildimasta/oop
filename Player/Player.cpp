#include <iostream>
#include "Player.h"

Player::Player(): health(MAX_HEALTH), score(START_SCORE){}

Player::Player(int hp, int score) : health(hp), score(score){}

int Player::getHealth() {
    return health;
}

int Player::getScore() {
    return score;
}

void Player::setHealth(int newHealth) {
    if(newHealth > MAX_HEALTH){
        health = MAX_HEALTH;
    }else if (newHealth < MIN_HEALTH){
        health = MIN_HEALTH;
    }else{
        health = newHealth; 
    }
}

void Player::setScore(int newScore) {
    if (newScore < 0) {
        score = 0;
    }else{
        score = newScore;
    }
}