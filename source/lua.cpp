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
template < , typename vectorType>
std::vector< cComponent<> > getTable( std::string tableName )
{
	std::vector< vectorType > newVector;
	lua_pushstring( l, tablename )
	lua_gettable( l, 1 )
	lua_pushnil( L );
	while ( lua_next( L, -2 ) != 0 ) 
	{
		lua_tostring( lua_type( L, -2 ) ),
		lua_tointeger( L, lua_type( L, -1 ) ),
	}
	lua_pop( L, 1 ); 
	return
}
*/
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

