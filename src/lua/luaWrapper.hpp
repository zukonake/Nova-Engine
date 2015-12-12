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

class cLuaWrapper //singleton
{
	friend class cInitializer;
	typedef std::vector< boost::any > universalArray;

	lua_state *L;

	void error( std::string message );
	table convertTable();
	universalArray convertTableToArray( std::unique_ptr< table > target );
	template < typename variableType >
	variableType convertVariable( int luaIndex );

	cLuaWrapper() {};
	void operator=( cLuaWrapper const& ) = delete;
	cLuaWrapper( cLuaWrapper const& ) = delete;
public:
	template < typename variableType >
	variableType getGlobal( std::string variableName );
	template < typename variableType >
	variableType runFunction( std::string functionName, std::string argument );
	bool openScript( std::string fileName );

	void initialize();
	static cLuaWrapper& newInstance();
	~cLuaWrapper();
};

/*
Exceptions
	> 01 - Lua error
*/
#endif
