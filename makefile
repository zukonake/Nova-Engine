SOURCE_PATH = src/
OBJ_PATH = build/obj/
DEBUG_PATH = bin/debug/Nova-Game_D
RELEASE_PATH = bin/release/Nova-Game
TARGET_PATH = $(DEBUG_PATH)
INCLUDE_PATH = $(SOURCE_PATH)
LIBRARY_PATH = lib/
SOURCES = $(shell find $(SOURCE_PATH) -type f -name "*.cpp")
OBJS = $(SOURCES:.cpp=.o)
CXX = g++
DEBUG = -g
STD = -std=c++14
LIBS = -liblua -libdl -lSDL2
INCFLAG = -I $(INCLUDE_PATH)
LIBFLAG = -L $(LIBRARY_PATH)
CXXFLAGS = -Wall
CFLAGS = $(STD) $(CXXFLAGS) $(LIBS) $(DEBUG) $(INCFLAG) $(LIBFLAG) -c
LFLAGS = $(STD) $(CXXFLAGS) $(LIBS) $(DEBUG) $(INCFLAG) $(LIBFLAG)

.PHONY : depend clean

all : $(TARGET_PATH)

$(TARGET_PATH) : $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(TARGET_PATH)

.cpp.o :
	$(CXX) $(CFLAGS) $< -o $@

clean :
	$(RM) $(OBJ_PATH)*.o *~ $(TARGET_PATH)

depend : $(SOURCES)
	makedepend $(INCFLAG) $^

# DO NOT DELETE
