SOURCE_PATH = source/
OBJ_PATH = $(SOURCE_PATH)obj/
DEBUG_PATH = $(SOURCE_PATH)debug/Aeon
RELEASE_PATH = release/Aeon
TARGET_PATH = $(DEBUG_PATH)
OBJS = $(OBJ_PATH)main.o $(OBJ_PATH)game.o $(OBJ_PATH)fileload.o $(OBJ_PATH)interface.o$(OBJ_PATH)entity.o $(OBJ_PATH)ai.o $(OBJ_PATH)board.o $(OBJ_PATH)tileset.o $(OBJ_PATH)tile.o $(OBJ_PATH)present.o $(OBJ_PATH)flagoperator.o $(OBJ_PATH)flag.o $(OBJ_PATH)global.o
CC = g++
DEBUG = -g
STD = -std=c++11
CFLAGS = $(STD) -Wall -c $(DEBUG)
LFLAGS = $(STD) -Wall $(DEBUG)

$(TARGET_PATH) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET_PATH)

$(OBJ_PATH)main.o : $(SOURCE_PATH)main.cpp $(SOURCE_PATH)game.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)main.cpp

$(OBJ_PATH)game.o : $(SOURCE_PATH)game.cpp $(SOURCE_PATH)fileload.cpp $(SOURCE_PATH)interface.o $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)ai.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)tileset.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)present.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)flag.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)game.cpp

$(OBJ_PATH)fileload.o : $(SOURCE_PATH)fileload.cpp $(SOURCE_PATH)fileload.hpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)fileload.cpp

$(OBJ_PATH)interface.o : $(SOURCE_PATH)interface.cpp $(SOURCE_PATH)interface.hpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)interface.cpp

$(OBJ_PATH)entity.o : $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)entity.hpp $(SOURCE_PATH)ai.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)entity.cpp

$(OBJ_PATH)ai.cpp : $(SOURCE_PATH)ai.cpp $(SOURCE_PATH)ai.hpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)ai.cpp


$(OBJ_PATH)board.o : $(SOURCE_PATH)board.cpp $(SOURCE_PATH)board.hpp $(SOURCE_PATH)tileset.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)board.cpp

$(OBJ_PATH)tileset.o : $(SOURCE_PATH)tileset.cpp $(SOURCE_PATH)tileset.hpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)present.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)tileset.cpp

$(OBJ_PATH)tile.o : $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)tile.hpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)tile.cpp

$(OBJ_PATH)present.o : $(SOURCE_PATH)present.cpp $(SOURCE_PATH)present.hpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)present.cpp

$(OBJ_PATH)flagoperator.o : $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)flagoperator.hpp $(SOURCE_PATH)flag.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)flagoperator.cpp

$(OBJ_PATH)flag.o : $(SOURCE_PATH)flag.cpp $(SOURCE_PATH)flag.hpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)flag.cpp

$(OBJ_PATH)global.o : $(SOURCE_PATH)global.cpp $(SOURCE_PATH)global.hpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)global.cpp
