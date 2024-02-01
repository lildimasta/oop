#ifndef FILECOMMAND_H
#define FILECOMMAND_H

#include "../Logger/KeyCommandMsg.h"
#include "../Logger/UKeyCommandMsg.h"
#include "../Logger/Logger.h"

#include <fstream>
#include <iostream>
#include <map>
#include <unordered_set>

class FileCommand :  public ICommandHandler {
private:
    std::ifstream inputFile;
    Command stringToCommand(std::string commandString);
    std::map<Command, char> commandMap;
    std::unordered_set<char> assignedKeys;
    void setDefaultSettings();
    void checkAllCommands();

public:
    FileCommand(std::string fileName);

    Command handleCommand();

    std::map<Command, char> getCommandMap();
    std::unordered_set<char> getAssignedKeys();

    ~FileCommand();
};

#endif