#include <iostream>
#include "GameField.h"

GameField::GameField() : width(MAX_WIDTH), height(MAX_HEIGHT),
entranceX(ENTRANCE), entranceY(ENTRANCE), exitX(MAX_WIDTH - 1), exitY(MAX_HEIGHT - 1)
{
    cells = new Cell*[width];
    for (int i = 0; i < width; i++) {
        cells[i] = new Cell[height];
    }
    exitX = width - 1;
    exitY = height - 1;
}

GameField::GameField(int w, int h) : width(w), height(h),
entranceX(ENTRANCE), entranceY(ENTRANCE), exitX(MAX_WIDTH - 1), exitY(MAX_HEIGHT - 1)
{
    if (w > MAX_WIDTH || w < MIN_WIDTH_HEIGHT || h > MAX_HEIGHT || h < MIN_WIDTH_HEIGHT) {
        width = MAX_WIDTH;
        height = MAX_HEIGHT;
    }
    cells = new Cell*[width];
    for (int i = 0; i < width; i++) {
        cells[i] = new Cell[height];
    }

    exitX = width - 1;
    exitY = height - 1;
}

GameField::GameField(const GameField& other) : width(other.width), height(other.height), 
entranceX(other.entranceX), entranceY(other.entranceY), exitX(other.exitX), exitY(other.exitY)
{
    cells = new Cell*[width];
    for (int i = 0; i < width; i++) {
        cells[i] = new Cell[height];
        for (int j = 0; j < height; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

GameField& GameField::operator=(const GameField& other){
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;

    width = other.width;
    height = other.height;
    entranceX = other.entranceX;
    entranceY = other.entranceY;
    exitX = other.exitX;
    exitY = other.exitY;

    cells = new Cell*[width];
    for (int i = 0; i < width; i++) {
        cells[i] = new Cell[height];
        for (int j = 0; j < height; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }

    return *this;
}

GameField::GameField(GameField&& other) : cells(other.cells), width(other.width), height(other.height), 
entranceX(other.entranceX), entranceY(other.entranceY), exitX(other.exitX), exitY(other.exitY)
{
    other.cells = nullptr;
    other.width = 0;
    other.height = 0;
    other.entranceX = 0;
    other.entranceY = 0;
    other.exitX = 0;
    other.exitY = 0;
}

GameField& GameField::operator=(GameField&& other){
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;

    cells = other.cells;
    width = other.width;
    height = other.height;
    entranceX = other.entranceX;
    entranceY = other.entranceY;
    exitX = other.exitX;
    exitY = other.exitY;

    other.cells = nullptr;
    other.width = 0;
    other.height = 0;
    other.entranceX = 0;
    other.entranceY = 0;
    other.exitX = 0;
    other.exitY = 0;

    return *this;
}

GameField::~GameField() {
    if(cells == nullptr){
        return;
    }
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}

Cell& GameField::getCell(int x, int y){
    return cells[x][y];
}

int GameField::getWidth(){
    return width;
}

int GameField::getHeight(){
    return height;
}

int GameField::getEntranceX(){
    return entranceX;
}

int GameField::getEntranceY(){
    return entranceY;
}

int GameField::getExitX(){
    return exitX;
}

int GameField::getExitY(){
    return exitY;
}

void GameField::setEntrance(int x , int y){
    if((x <= width && x >= ENTRANCE) && (y <= height && y >= ENTRANCE)){
        entranceX = x;
        entranceY = y;
    }else{
        std::cout << "Неверная точка входа\n";
    }
}

void GameField::setExit(int x , int y){
    if((x <= width && x >= MIN_WIDTH_HEIGHT) && (y <= height && y >= MIN_WIDTH_HEIGHT)){
        exitX = x;
        exitY = y;
    }else{
        std::cout << "Неверная точка выхода\n";
    }
}