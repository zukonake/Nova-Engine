//lua.hpp
#ifndef LUA_HPP
#define LUA_HPP

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

class cLua
{
	lua_state *L;
	cLua();
	~cLua();
}

#endif
