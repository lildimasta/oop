#include <iostream>
#include "inputManager.h"

int inputManager::chooseDifficulty() {
    int choice;
    std::cout << "Выберите уровень сложности:\n";
    std::cout << "1. Легкий (10 жизней)\n";
    std::cout << "2. Средний (5 жизней)\n";
    std::cout << "3. Тяжелый (3 жизни)\n";
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Неверный ввод, автоматически выбрана легкая сложность.\n";
        return 10;
    }
    switch (choice) {
        case 1:
            return 10;
            break;
        case 2:
            return 5;
            break;
        case 3:
            return 3;
            break;
        default:
            std::cout << "Неверно выбрана сложность, автоматически выбрана легкая\n";
            return 10;
            break;
    }
}

int inputManager::chooseField(){
    int choice;
    std::cout << "Выберите размеры поля:\n";
    std::cout << "1. 15 * 15\n";
    std::cout << "2. 10 * 10\n";
    std::cout << "3. 5 * 5\n";
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Неверный ввод, автоматически выбран размер 15 * 15.\n";
        return 15;
    }
    switch (choice) {
        case 1:
            return 15;
            break;
        case 2:
            return 10;
            break;
        case 3:
            return 5;
            break;
        default:
            std::cout << "Неверно выбрано поле, автоматически выбрано 1\n";
            return 15;
            break;
    }
}