SOURCE_PATH = src/
OBJ_PATH = build/obj/
DEBUG_PATH = bin/debug/Nova-Game_D
RELEASE_PATH = bin/release/Nova-Game
TARGET_PATH = $(DEBUG_PATH)
INCLUDE_PATH = $(SOURCE_PATH)
LIBRARY_PATH = lib/
DEPEND_PATH = build/depend
SOURCES = $(shell find $(SOURCE_PATH) -type f -name "*.cpp" -printf '%p ')
#STO = $(OBJ_PATH)$(shell basename -a $(SOURCES))
OBJS = $(SOURCES:.cpp=.o)
CXX = g++
DEBUG = -g
STD = -std=c++14
LDLIBS = -llua -ldl -lSDL2
INCFLAGS = -I $(INCLUDE_PATH)
LIBFLAGS = -L $(LIBRARY_PATH)
CXXFLAGS = $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)
LDFLAGS = $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)

.PHONY : depend clean all

all : $(SOURCES) $(TARGET_PATH)

$(TARGET_PATH) : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ >> make.log

depend : $(SOURCES)
	$(CXX) $(CXXFLAGS) -MM $(SOURCES) > $(DEPEND_PATH)

clean :
	$(RM) $(OBJ_PATH)*.o *~ $(TARGET_PATH) $(DEPEND_PATH)

-include $(DEPEND_PATH)
