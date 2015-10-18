//luaWrapper.cpp
#include "luaWrapper.hpp"

cLuaTable cLuaWrapper::convertTable()
{
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
		else if( lua_isnil( L, -1 ) )
		{
			target.synchronizeEntry< void* >( cLuaTableEntry< void* >( key, NULL ); // Not sure if it's safe
		}
		else
		{
			lua_pop( L, 1 );
			lua_pushstring( L, "Unknown variable type for key: " + key );
			lua_error( L );
		}
	}
	lua_pop( L, 1 ); 
	return target;
}

template < typename variableType >
variableType cLuaWrapper::convertVariable( int luaIndex )
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
		return ( lua_Number )lua_tonumber( L, index );
	}
	else if( lua_istable( L, index ) )
	{
		return ( cLuaTable )convertTable();
	}
	else if( lua_isnil( L, index ) )
	{
		return ( void* ) NULL; // Not sure if safe
	}
	else
	{
		lua_pop( L, 1 );
		lua_pushstring( L, "Unknown variable type");
		lua_error( L );
	}
}

cLuaTable cLuaWrapper::getTable( std::string tableName ) // I think it should work...
{
	lua_pushstring( l, tablename );
	lua_gettable( l, 1 );
	return convertTable()
}

template < typename variableType >
variableType cLuaWrapper::getVariable( std::string variableName )
{
	lua_getglobal( L, variableName );
	return convertVariable< variableType >( -1 );
}

//TODO needs argument list ( ... )
template < typename variableType >
variableType cLuaWrapper::runFunction( std::string functionName, std::string argument )
{
	lua_getglobal( functionName );
	if( not lua_isfunction( L, -1 ) )
	{
		lua_pop( L, 1 );
		lua_pushstring( L, functionName .. " is not a function." );
		lua_error( L );
		return NULL;
	}
	if( lua_pcall( L, 1, 1, 0 ) != 0 )
	{
		lua_pop( L, 1 );
		lua_pushstring( L, "Error running " .. functionName .. " function." );
		lua_error( L );
		return NULL;
	}
	variableType returnedVariable = convertVariable< variableType >( -1 );
	lua_pop( L, 1 );
	return returnedVariable;
}


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

