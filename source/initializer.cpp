//initializer.cpp
extern "C"
{
	#include "lualib.h"
	#include "lauxlib.h"
}

#include "initializer.hpp"
#include "global.hpp"

cInitializer::cInitializer(lua_state* L)
{
	luaL_openlibs(L);
	//TODO list and read files and send them to constructors
}
