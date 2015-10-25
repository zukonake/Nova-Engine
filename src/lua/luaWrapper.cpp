//luaWrapper.cpp
#include "luaWrapper.hpp"

void cLuaWrapper::error( std::string message = std::string("") )
{
	lua_pushstring( L, message );
	lua_error( L );
}

std::map< std::string, boost::any > cLuaWrapper::convertTable()
{
	lua_pushnil( L );
	std::map< std::string, boost::any > target;
	while ( lua_next( L, -2 ) != 0 ) 
	{
		std::string key = lua_tostring( L, -2 );
		if( lua_isboolean( L, -1 ) )
		{
			target.insert( key, ( bool )lua_tobool( L, -1 ) );
		}
		else if( lua_isstring( L, -1 ) )
		{
			target.insert( key, ( std::string )lua_tostring( L, -1 ) );
		}
		else if( lua_isnumber( L, -1 ) )
		{
			target.insert( key, ( double )lua_tonumber( L, -1 ) );
		}
		else if( lua_istable( L, -1 ) )
		{
			target.insert( key, ( std::map< std::string, boost::any > )convertTable() );
		}
		else if( lua_isnil( L, -1 ) )
		{
			target.insert( key, ( void* )NULL );
		}
		else
		{
			lua_pop( L, 1 );
			error();
			return NULL;
		}
	}
	lua_pop( L, 1 ); 
	return target;
}

std::vector< boost::any > cLuaWrapper::convertTableToArray( std::map< std::string, boost::any >* table )
{
	std::vector< boost::any > array;
	for( auto const &iterator : table )
	{
		array.push_back( iterator.second );
	}
	return array;
}

template <>
bool cLuaWrapper::convertVariable( int luaIndex )
{
	if( lua_isboolean( L, index ) )
	{
		return ( bool )lua_tobool( L, index );
	}
	else
	{
		lua_pop( L, 1 );
		error();
		return NULL;
	}
}

template <>
double cLuaWrapper::convertVariable( int luaIndex )
{
	if( lua_isnumber( L, index ) )
	{
		return ( double )lua_tonumber( L, index );
	}
	else
	{
		lua_pop( L, 1 );
		error();
		return NULL;
	}
}

template <>
std::string cLuaWrapper::convertVariable( int luaIndex )
{
	if( lua_isstring( L, index ) )
	{
		return ( std::string )lua_tostring( L, index );
	}
	else
	{
		lua_pop( L, 1 );
		error();
		return NULL;
	}
}

template <>
std::vector< boost::any > cLuaWrapper::convertVariable( int luaIndex )
{
	if( lua_istable( L, index ) )
	{
		return convertTableToArray( convertTable() );
	}
	else
	{
		lua_pop( L, 1 );
		error();
		return NULL;
	}
}

template <>
std::map< std::string, boost::any > cLuaWrapper::convertVariable( int luaIndex )
{
	if( lua_istable( L, index ) )
	{
		return convertTable();
	}
	else
	{
		lua_pop( L, 1 );
		error();
		return NULL;
	}
}

template <>
void* cLuaWrapper::convertVariable( int luaIndex )
{
	if( lua_isnil( L, index ) ){
	{
		return ( void* )NULL;
	}
	else
	{
		lua_pop( L, 1 );
		error();
		return NULL;
	}
}

template < typename variableType >
variableType cLuaWrapper::getGlobal( std::string variableName )
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

