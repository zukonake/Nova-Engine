#include "initializer.hpp"
#include "global.hpp"
extern "C"
{
	#include "lualib.h"
	#include "lauxlib.h"
}

cInitializer::cInitializer(lua_state* L)
{
	luaL_openlibs(L);
	//TODO list and read files and send them to constructors
}
