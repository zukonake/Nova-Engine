SOURCE_PATH = source/
OBJ_PATH = $(SOURCE_PATH)obj/
DEBUG_PATH = bin/debug/Aeon
RELEASE_PATH = bin/release/Aeon
TARGET_PATH = $(DEBUG_PATH)
OBJS = $(OBJ_PATH)main.o $(OBJ_PATH)game.o $(OBJ_PATH)initilizer.o $(OBJ_PATH)lua.o $(OBJ_PATH)interface.o $(OBJ_PATH)boardGenerator.o $(OBJ_PATH)entity.o $(OBJ_PATH)entitySubtype.o $(OBJ_PATH)ai.o $(OBJ_PATH)board.o $(OBJ_PATH)block.o $(OBJ_PATH)blockSubtype.o $(OBJ_PATH)tile.o $(OBJ_PATH)componentHandler.o $(OBJ_PATH)component.o $(OBJ_PATH)global.o
CC = g++
DEBUG = -g
STD = -std=c++11
LIBS = -liblua -libdl
CFLAGS = $(STD) -Wall -c $(DEBUG) $(LIBS)
LFLAGS = $(STD) -Wall $(DEBUG) $(LIBS)

$(TARGET_PATH) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET_PATH)

$(OBJ_PATH)main.o : $(SOURCE_PATH)main.cpp $(SOURCE_PATH)game.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)main.cpp

$(OBJ_PATH)game.o : $(SOURCE_PATH)game.cpp $(SOURCE_PATH)game.hpp $(SOURCE_PATH)lua.cpp $(SOURCE_PATH)interface.cpp $(SOURCE_PATH)boardGenerator.cpp $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)global.cpp

$(OBJ_PATH)initializer.o : $(SOURCE_PATH)lua.cpp $(SOURCE_PATH)interface.o $(SOURCE_PATH)boardGenerator.cpp $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)entitySubtype.cpp $(SOURCE_PATH)ai.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)block.cpp $(SOURCE_PATH)blockSubtype.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)componentHandler.cpp $(SOURCE_PATH)component.cpp $(SOURCE_PATH)global.cpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)initializer.cpp

$(OBJ_PATH)lua.o : $(SOURCE_PATH)lua.cpp $(SOURCE_PATH)lua.hpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)lua.cpp

$(OBJ_PATH)interface.o : $(SOURCE_PATH)interface.cpp $(SOURCE_PATH)interface.hpp
	$(CC) $(CFLAGS) $(SOURCE_PATH)interface.cpp


$(OBJ_PATH)boardGenerator.o : $(SOURCE_PATH)boardGenerator.cpp $(SOURCE_PATH)boardGenerator.hpp $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)
	$(CC) $(CFLAGS) $(SOURCE_PATH)interface.cpp

$(OBJ_PATH)entity.o : $(SOURCE_PATH)entity.cpp $(SOURCE_PATH)entity.hpp $(SOURCE_PATH)entitySubtype.cpp $(SOURCE_PATH)ai.cpp $(SOURCE_PATH)board.cpp $(SOURCE_PATH)tile.cpp $(SOURCE_PATH)flagoperator.cpp $(SOURCE_PATH)global.cpp
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
