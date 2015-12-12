SOURCE_PATH = src/
OBJ_PATH = build/obj
DEBUG_PATH = bin/debug/Nova-Game_D
RELEASE_PATH = bin/release/Nova-Game
TARGET_PATH = $(DEBUG_PATH)
INCLUDE_PATH = $(SOURCE_PATH)
LIBRARY_PATH = lib/
define SOURCES
$(OBJ_PATH)main.cpp
$(OBJ_PATH)server.cpp
$(OBJ_PATH)client.cpp
$(OBJ_PATH)interfaceHandler.cpp
$(OBJ_PATH)camera.cpp
$(OBJ_PATH)interface.cpp
$(OBJ_PATH)interfaceComponent.cpp
$(OBJ_PATH)entity.cpp
$(OBJ_PATH)entityControl.cpp
$(OBJ_PATH)entityAction.cpp
$(OBJ_PATH)entitySubtype.cpp
$(OBJ_PATH)board.cpp
$(OBJ_PATH)boardGenerator.cpp
$(OBJ_PATH)block.cpp
$(OBJ_PATH)blockSubtype.cpp
$(OBJ_PATH)luaWrapper.cpp
$(OBJ_PATH)typedef.cpp
$(OBJ_PATH)global.cpp
endef
OBJS = $(OBJS:.cpp=.o)
CC = g++
DEBUG = -g
STD = -std=c++14
LIBS = -liblua -libdl -lSDL2
INCFLAG = -I $(INCLUDE_PATH)
LIBFLAG = -L $(LIBRARY_PATH)
CFLAGS = $(STD) -Wall $(LIBS) $(DEBUG) $(INCFLAG) $(LIBFLAG) -c
LFLAGS = $(STD) -Wall $(LIBS) $(DEBUG) $(INCFLAG) $(LIBFLAG)

.PHONY : depend clean

default : $(TARGET_PATH)

$(TARGET_PATH) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET_PATH)

.cpp.o :
	$(CC) $(CFLAGS) $< -o $@

clean :
	$(RM) $(OBJ_PATH)*.o *~ $(TARGET_PATH)

depend : $(SOURCES)
	makedepend $(INCFLAG) $^
