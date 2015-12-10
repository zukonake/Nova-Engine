//luaWrapper.hpp
#ifndef LUAWRAPPER_HPP
#define LUAWRAPPER_HPP

#include <string>
#include <vector>
#include <boost/any.hpp>
extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
//
#include <typedef.hpp>

class cLuaWrapper
{
	friend class cInitializer;
	lua_state *L;
	void error( std::string message );
	table convertTable();
	std::vector< boost::any > convertTableToArray( table* target );
	template < typename variableType >
	variableType convertVariable( int luaIndex );
public:
	template < typename variableType >
	variableType getGlobal( std::string variableName );
	template < typename variableType >
	variableType runFunction( std::string functionName, std::string argument );
	bool openScript( std::string fileName );
	cLuaWrapper();
	~cLuaWrapper();
};


#endif
