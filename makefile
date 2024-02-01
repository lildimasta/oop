CC = g++
CFLAGS = -std=c++20

SRC = main.cpp ./Player/Player.cpp ./Manager/gameManager.cpp ./OtherActions/inputManager.cpp ./Field/Cell.cpp ./Field/GameField.cpp ./OtherActions/PrintField.cpp ./Event/eventInterface.cpp ./Event/PositiveEvent.cpp ./OtherActions/GameLevel.cpp ./Event/NegativeEvent.cpp ./Event/ChangeCoordsEvent.cpp Game.cpp ./Commands/CommandHandler.cpp ./Commands/TerminalCommand.cpp ./Commands/FileCommand.cpp ./Commands/CommandProcessor.cpp ./Manager/controller.cpp ./OtherActions/EventSymbolSelector.cpp ./observers/IObserver.cpp ./observers/Observer.cpp ./observers/GameTracker.cpp ./observers/PlayerObserver.cpp ./Logger/IMessage.cpp ./Logger/MessageEmitter.cpp ./Logger/ConsoleLog.cpp ./Logger/FileLog.cpp ./Logger/Logger.cpp ./Logger/PlayerWonMsg.cpp ./Logger/PlayerLostMsg.cpp ./Logger/KeyCommandMsg.cpp ./Logger/NewGameMsg.cpp ./Logger/UKeyCommandMsg.cpp
OBJ = $(SRC:.cpp=.o)


TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)