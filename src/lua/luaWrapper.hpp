//luaWrapper.hpp
#ifndef LUAWRAPPER_HPP
#define LUAWRAPPER_HPP

#include <string>
#include <vector>

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
	cLuaTable convertTable();
	template < typename variableType >
	variableType convertVariable( int luaIndex );
	public:
	template < typename variableType >
	variableType getVariable( std::string variableName );
	template < typename variableType >
	variableType runFunction( std::string functionName, std::string argument );
	bool openScript( std::string fileName );
	cLuaWrapper();
	~cLuaWrapper();
}


#endif
