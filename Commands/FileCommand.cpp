#include "FileCommand.h"


FileCommand::FileCommand(std::string fileName) : inputFile(fileName){
    if (!inputFile.is_open()) {
        std::cout << "Не удалось открыть файл: " << fileName << "\n";
        return;
    }
    char key;
    std::string commandString;
    std::string line;

    while (std::getline(inputFile, line)) {

        size_t spacePoz = line.find(' ');
        if(spacePoz != std::string::npos){
            commandString = line.substr(0, spacePoz);
            key = line[spacePoz+1];
        }else{
            commandString = line;
            key = '.';
        }
        Command cmd = stringToCommand(commandString);
        if (cmd != Command::UNKNOWN) {
            if(key == '.'){
                std::cout << "Ошибка: команда " << commandString << " не имеет назначенной клавиши!\n";
                setDefaultSettings();
                return;
            }
            if (commandMap.find(cmd) != commandMap.end()) {
                std::cout << "На команду " << commandString << " назначено больше одной клавиши\n";
                setDefaultSettings();
                return;
            }
            if (assignedKeys.find(key) != assignedKeys.end()) {
                std::cout << "На клавишу " << key << " назначено более одной команды\n";
                setDefaultSettings();
                return;
            }
            assignedKeys.insert(key);
            commandMap[cmd] = key;
        }
    }
    checkAllCommands();
}


void FileCommand::checkAllCommands(){
    for(Command cmd : {Command::UP, Command::DOWN, Command::LEFT, Command::RIGHT, Command::QUIT, Command::INFO}){
        if(commandMap.find(cmd) == commandMap.end()){
            std::cout << "Одна из команд отсутствует в файле!\n";
            setDefaultSettings();
            return;
        }
    }
}

void FileCommand::setDefaultSettings(){
    std::cout << "Установлены настройки по умлочанию\n";
    commandMap[Command::UP] = 'w';
    commandMap[Command::RIGHT] = 'd';
    commandMap[Command::DOWN] = 's';
    commandMap[Command::LEFT] = 'a';
    commandMap[Command::QUIT] = 'q';
    commandMap[Command::INFO] = 'i';
    assignedKeys = {'w', 'd', 's', 'a', 'q', 'i'};
}


Command FileCommand::handleCommand() {
    Logger * logger = Logger::getInstance();
    
    char userInput;
    std::cin >> userInput;
    for (auto pair : commandMap) {
        if (pair.second == userInput) {

            logger->logMessage(KeyCommandMsg(userInput, pair.first));

            return pair.first;
        }
    }
    logger->logMessage(UKeyCommandMsg(userInput));
    
    return Command::UNKNOWN;
}

Command FileCommand::stringToCommand(std::string commandString) {
    if (commandString == "UP") {
        return Command::UP;
    } else if (commandString == "DOWN") {
        return Command::DOWN;
    } else if (commandString == "LEFT") {
        return Command::LEFT;
    } else if (commandString == "RIGHT") {
        return Command::RIGHT;
    } else if (commandString == "QUIT") {
        return Command::QUIT;
    } else if (commandString == "INFO") {
        return Command::INFO;
    }
    std::cout << "Найдена неизвестная команда " << commandString << "\n";
    setDefaultSettings();
    return Command::UNKNOWN;
}

std::map<Command, char> FileCommand::getCommandMap(){
    return commandMap;
}

std::unordered_set<char> FileCommand::getAssignedKeys(){
    return assignedKeys;
}


FileCommand::~FileCommand() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
}