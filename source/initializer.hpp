//initializer.hpp
#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

extern "C"
{
	#include "lua.h"
}

class cInitializer
{
	cInitializer(lua_state* L);
}

#endif
