//luaWrapper.hpp
#ifndef LUAWRAPPER_HPP
#define LUAWRAPPER_HPP

#include <string>

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include "luaTable.hpp"

class cLuaWrapper
{
	friend class cInitializer;
	lua_state *L;
	public:
	template < typename variableType >
	variableType getVariable( std::string variableName );
	cLuaTable getTable( std::string tableName );
	template < typename variableType >
	variableType runFunction( std::string functionName );
	bool openScript( std::string fileName );
	cLuaWrapper();
	~cLuaWrapper();
}


#endif
