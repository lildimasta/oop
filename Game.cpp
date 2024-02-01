#include <iostream>
#include "Game.h"
#include "./Manager/controller.h"

void Game::StartGame() {

    Logger* logger = Logger::getInstance();
    std::cout << "Куда выводить логи : 1 - консоль, 2 - файл 3 - косоль/файл ?\n";
    int logtype;
    std::cin >> logtype;

    switch (logtype) {
        case 1:
            logger->addStream(true, false);
            break;
        case 2:
            logger->addStream(false, true);
            break;
        case 3:
            logger->addStream(true, true);
            break;
        default:
            std::cout << "Некорректный выбор, выбрано консоль/файл\n";
            logger->addStream(true, true);
    }

    char choice = ' ';
    std::cout << "Хотите начать игру - y/n\n";
    while (choice != 'n') {

        while (choice != 'y' && choice != 'n') {
            std::cin >> choice;
        }

        if (choice == 'n') {
            std::cout << "Игра завершена\n";
            return;
        }

        GameLevel gameLevel;
        inputManager input;

        int initialHealth = input.chooseDifficulty();

        Player player(initialHealth, 0);

        GameField field = gameLevel.generate1();
        gameManager gameM(player, field);

        EventInterface* event = new PositiveEffectEvent(gameM);
        EventInterface* event2 = new NegativeEvent(gameM);
        EventInterface* event3 = new ChangeCoordsEvent(gameM, field);
        field.getCell(1, 1).setEvent(event);
        field.getCell(1, 0).setEvent(event2);
        field.getCell(2, 0).setEvent(event3);

        char ch;
        ch = ' ';
        
        std::cout << "Выберите источник команд: - t терминал, f файл\n";
        while (ch != 't' && ch != 'f') {
            std::cin >> ch;
        }

        ICommandHandler* cmdHandler;
        if (ch == 't') {
            cmdHandler = new TerminalCommand();
        } else if (ch == 'f') {
            std::string fileName = "./commands.txt";
            cmdHandler = new FileCommand(fileName);
        }
        Controller mover;
        CommandProcessor cmdProcessor(cmdHandler);

        Observer obs(gameM);
        PlayerObserver pl(player);
        GameTracker tracker(player, field, gameM, obs, pl);
        
        PrintField FirstPrint(field);
        FirstPrint.print(gameM.getX(), gameM.getY());

        while (true) {
            Command cmd = cmdProcessor.processInput();
            mover.ProcessComands(gameM, cmd);
            if (cmd == QUIT) {
                break;
            }
            if(tracker.CheckState()){
                break;
            }
            tracker.Track();
        }
        choice = ' ';
        std::cout << "Хотите начать новую игру - y/n\n";
        while (choice != 'y' && choice != 'n') {
            std::cin >> choice;
            if(choice == 'y'){
                logger->logMessage(NewGameMsg(true));
            }else if (choice == 'n'){
                logger->logMessage(NewGameMsg(false));
            }
        }
    }
    logger->destroy();
}