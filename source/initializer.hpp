//initializer.hpp
#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

extern "C"
{
	#include "lua.h"
}

#include "lua/luaTable.hpp"
#include "lua/luaWrapper.hpp"

class cInitializer
{
	cInitializer(lua_state* L);
}

#endif
