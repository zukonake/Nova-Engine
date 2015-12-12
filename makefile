SOURCE_PATH = src/
OBJ_PATH = build/obj/
DEBUG_PATH = bin/debug/Nova-Game_D
RELEASE_PATH = bin/release/Nova-Game
TARGET_PATH = $(DEBUG_PATH)
INCLUDE_PATH = $(SOURCE_PATH)
LIBRARY_PATH = lib/
SOURCES = $(shell find $(SOURCE_PATH) -type f -name "*.cpp")
define OBJS
$(OBJ_PATH)main.o
$(OBJ_PATH)server.o
$(OBJ_PATH)client.o
$(OBJ_PATH)interfaceHandler.o
$(OBJ_PATH)camera.o
$(OBJ_PATH)interface.o
$(OBJ_PATH)interfaceComponent.o
$(OBJ_PATH)entity.o
$(OBJ_PATH)entityControl.o
$(OBJ_PATH)entityAction.o
$(OBJ_PATH)entitySubtype.o
$(OBJ_PATH)board.o
$(OBJ_PATH)boardGenerator.o
$(OBJ_PATH)block.o
$(OBJ_PATH)blockSubtype.o
$(OBJ_PATH)luaWrapper.o
$(OBJ_PATH)typedef.o
$(OBJ_PATH)global.o
endef
CXX = g++
DEBUG = -g
STD = -std=c++14
LDLIBS = -liblua -libdl -lSDL2
INCFLAGS = -I $(INCLUDE_PATH)
LIBFLAGS = -L $(LIBRARY_PATH)
CXXFLAGS = $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)
LDFLAGS = $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)

.PHONY : depend clean

all : $(TARGET_PATH)

$(TARGET_PATH) : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET_PATH)

.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ_PATH)*.o *~ $(TARGET_PATH)
	mv -f makefile.bak makefile

depend : $(SOURCES)
#
