SOURCE_PATH = src/
OBJ_PATH = build/obj
DEBUG_PATH = bin/debug/Nova-Game-D
RELEASE_PATH = bin/release/Nova-Game
TARGET_PATH = $(DEBUG_PATH)
OBJS = $(OBJ_PATH)main.o $(OBJ_PATH)game.o $(OBJ_PATH)initilizer.o $(OBJ_PATH)lua.o $(OBJ_PATH)interface.o $(OBJ_PATH)boardGenerator.o $(OBJ_PATH)entity.o $(OBJ_PATH)entitySubtype.o $(OBJ_PATH)ai.o $(OBJ_PATH)board.o $(OBJ_PATH)block.o $(OBJ_PATH)blockSubtype.o $(OBJ_PATH)tile.o $(OBJ_PATH)componentHandler.o $(OBJ_PATH)component.o $(OBJ_PATH)global.o
CC = g++
DEBUG = -g
STD = -std=c++14
LIBS = -liblua -libdl
CFLAGS = $(STD) -Wall -c $(DEBUG) $(LIBS)
LFLAGS = $(STD) -Wall $(DEBUG) $(LIBS)

$(TARGET_PATH) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET_PATH)

$(OBJ_PATH)game.o : $(SOURCE_PATH)game.cpp $(SOURCE_PATH)game.hpp $(SOURCE_PATH)lua.cpp $(SOURCE_PATH)interface.cpp $(SOURCE_PATH)boardGenerator.cpp $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)global.cpp

$(OBJ_PATH)initializer.o : $(SOURCE_PATH)lua.cpp $(SOURCE_PATH)interface.o $(SOURCE_PATH)boardGenerator.cpp $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)entitySubtype.cpp $(SOURCE_PATH)ai.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)block.cpp $(SOURCE_PATH)blockSubtype.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)componentHandler.cpp $(SOURCE_PATH)component.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)initializer.cpp

$(OBJ_PATH)interface.o : $(SOURCE_PATH)interface.cpp $(SOURCE_PATH)interface.hpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)interface.cpp

$(OBJ_PATH)boardGenerator.o : $(SOURCE_PATH)boardGenerator.cpp $(SOURCE_PATH)boardGenerator.hpp $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)
	$(CC) $(CFLAGS) $(SOURCE_PATH)interface.cpp

$(OBJ_PATH)entity.o : $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)entity.hpp $(SOURCE_PATH)entitySubtype.cpp $(SOURCE_PATH)ai.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)entity.cpp

$(OBJ_PATH)entitySubtype.o :
	$(CC) $(CFLAGS) $(SOURCE_PATH)entitySubtype.cpp

$(OBJ_PATH)ai.cpp : $(SOURCE_PATH)ai.cpp $(SOURCE_PATH)ai.hpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)ai.cpp

$(OBJ_PATH)board.o : $(SOURCE_PATH)board.cpp $(SOURCE_PATH)board.hpp $(SOURCE_PATH)tileset.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)board.cpp

$(OBJ_PATH)block.o :
	$(CC) $(CFLAGS) $(SOURCE_PATH)block.cpp

$(OBJ_PATH)blockSubtype.o :
	$(CC) $(CFLAGS) $(SOURCE_PATH)blockSubtype.cpp

$(OBJ_PATH)tile.o : $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)tile.hpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)tile.cpp

$(OBJ_PATH)global.o : $(SOURCE_PATH)global.cpp $(SOURCE_PATH)global.hpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)global.cpp

$(OBJ_PATH)luaWrapper.o :
	$(CC) $(CFLAGS) $(SOURCE_PATH)luaWrapper.cpp

$(OBJ_PATH)luaTable.o :
	$(CC) $(CFLAGS) $(SOURCE_PATH)luaTable.cpp
