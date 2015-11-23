SOURCE_PATH = src/
OBJ_PATH = build/obj
DEBUG_PATH = bin/debug/Nova-Game_D
RELEASE_PATH = bin/release/Nova-Game
TARGET_PATH = $(DEBUG_PATH)
OBJS = 
CC = g++
DEBUG = -g
STD = -std=c++14
LIBS = -liblua -libdl
CFLAGS = $(STD) -Wall -c $(DEBUG) $(LIBS)
LFLAGS = $(STD) -Wall $(DEBUG) $(LIBS)

$(TARGET_PATH) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET_PATH)
