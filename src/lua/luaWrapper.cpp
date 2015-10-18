//luaWrapper.cpp
#include "luaWrapper.hpp"

template < typename variableType >
variableType cLuaWrapperWrapper::convertVariable( int index )
{
	if( lua_isboolean( L, index ) )
	{
		return ( bool )lua_tobool( L, index );
	}
	else if( lua_isstring( L, index ) )
	{
		return ( std::string )lua_tostring( L, index );
	}
	else if( lua_isnumber( L, index ) )
	{
		return ( int )lua_tointeger( L, index );
	}
	return NULL;
}

template < typename variableType >
variableType cLuaWrapperWrapper::getVariable( std::string variableName )
{
	lua_getglobal( L, variableName );
	return convertVariable< variableType >( -1 );
}
//TODO
template < typename vectorType>
cComponentHandler getTable( std::string tableName )
{
	lua_pushstring( l, tablename )
	lua_gettable( l, 1 )
	lua_pushnil( L );
	while ( lua_next( L, -2 ) != 0 ) 
	{
		std::string key = lua_tostring( L, -2 );
		switch( lua_type( L, -1 ) )
		{
			case LUA_TSTRING:
		}
	}
	lua_pop( L, 1 ); 
	return
}

/* TODO
conversionType cLuaWrapper::runFunction( std::string functionName )
{

}
*/

bool cLuaWrapper::openScript( std::string fileName )
{
	if (luaL_loadfile( L, fileName ) || lua_pcall( L, 0, 0, 0 ))
	{
		return -1;
	}
}

cLuaWrapper::cLuaWrapper()
{
	L = lua_newstate( 0, 0 );
	luaL_openlibs( L );
}

cLuaWrapper::~cLuaWrapper()
{
	lua_close( L );
}

