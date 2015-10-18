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
	lua_state *L;
	std::string fileName;
	template < typename variableType >
	variableType convertVariable( int index );
	template < typename variableType >
	variableType getVariable( std::string variableName );
	template < typename variableType >
	variableType getTable( std::string tableName );
	template < typename variableType >
	variableType runFunction( std::string functionName );
	bool openScript( std::string fileName );
	cLuaWrapper();
	~cLuaWrapper();
}


#endif
