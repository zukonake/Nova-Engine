SOURCE_PATH = src/
OBJ_PATH = build/obj
DEBUG_PATH = bin/debug/Nova-Game_D
RELEASE_PATH = bin/release/Nova-Game
TARGET_PATH = $(DEBUG_PATH)
INCLUDE_PATH = $(SOURCE_PATH)
OBJS =
CC = g++
DEBUG = -g
STD = -std=c++14
LIBS = -liblua -libdl -lSDL2
CFLAGS = $(STD) -Wall $(LIBS) $(DEBUG) -I $(SOURCE_PATH) -c
LFLAGS = $(STD) -Wall $(LIBS) $(DEBUG) -I $(SOURCE_PATH)

$(TARGET_PATH) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET_PATH)
