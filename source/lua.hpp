//lua.hpp
#ifndef LUA_HPP
#define LUA_HPP

#include <string>

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

template < typename variableType >
class cLua
{
	lua_state *L;
	std::string fileName;
	variableType getVariable( std::string variableName );
	variableType getTable( std::string tableName );
	variableType runFunction( std::string functionName );
	bool openScript( std::string fileName );
	cLua();
	~cLua();
}

#endif
