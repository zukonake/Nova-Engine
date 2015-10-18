//luaWrapper.cpp
#include "luaWrapper.hpp"

template < typename variableType >
variableType cLuaWrapper::getVariable( std::string variableName )
{
	lua_getglobal( L, variableName );
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
		return ( lua_Number )lua_tonumber( L, index );
	}
	else
	{
		return NULL;
	}
}

cLuaTable cLuaWrapper::getTable( std::string tableName ) // I think it should work...
{
	lua_pushstring( l, tablename );
	lua_gettable( l, 1 );
	lua_pushnil( L );
	cLuaTable target;
	while ( lua_next( L, -2 ) != 0 ) 
	{
		std::string key = lua_tostring( L, -2 );
		if( lua_isboolean( L, -1 ) )
		{
			target.synchronizeEntry< bool >( cLuaTableEntry< bool >( key, lua_tobool( L, -1 ) ) );
		}
		else if( lua_isstring( L, -1 ) )
		{
			target.synchronizeEntry< std::string >( cLuaTableEntry< std::string >( key, lua_tostring( L, -1 ) ) );
		}
		else if( lua_isnumber( L, -1 ) )
		{
			target.synchronizeEntry< lua_Number >( cLuaTableEntry< lua_Number >( key, lua_tonumber( L, -1 ) ) );
		}
		else if( lua_istable( L, -1 ) )
		{
			target.synchronizeEntry< cLuaTable >( cLuaTableEntry< cLuaTable >( key, getTable( tableName + key ) );
		}
		else
		{
			return NULL; //invalid table
		}
	}
	lua_pop( L, 1 ); 
	return target;
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

