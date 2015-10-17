//lua.hpp
#include "lua.hpp"

template <>
bool cLua::getVariable( std::string variableName )
{
	lua_getglobal( L, variableName );
	return ( bool )lua_tobool( L, -1 );
}

template <>
int cLua::getVariable( std::string variableName )
{
	lua_getglobal( L, variableName );
	return ( int )lua_tointeger( L, -1 );
}

template <>
std::string cLua::getVariable( std::string variableName )
{
	lua_getglobal( L, variableName );
	return ( std::string )lua_tostring( L, -1 );
}

/* TODO
conversionType cLua::runFunction( std::string functionName )
{

}
*/

bool cLua::openScript( std::string fileName )
{
	if (luaL_loadfile( L, fileName ) || lua_pcall( L, 0, 0, 0 ))
	{
		return -1;
	}
}

cLua::cLua()
{
	L = lua_newstate( 0, 0 );
	luaL_openlibs( L );
}

cLua::~cLua()
{
	lua_close( L );
}

