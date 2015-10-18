//lua.hpp
#include "lua.hpp"

//cLuaTableEntry

template < typename valueType >
valueType cLuaTableEntry::returnValue()
{
	return ( valueType )value;
}

std::string cLuaTableEntry::returnKey()
{
	return key;
}

template < typename valueType >
cLuaTableEntry::cLuaTableEntry( std:string _key, valueType _value )
	key( _key ),
	value( _value )
{
	
}

/////////////////////////////////////////////////
//cLuaTable

template < typename valueType >
int16_t cLuaTable::returnEntryIndex( std::string entryKey )
{
	for( uint16_t i = 0; i < table.size(); i++ )
	{
		if( static_cast< cLuaTableEntry< valueType >* >( table[i] )->key == entryKey )
		{
			return i;
		}
	}
	return -1;
}

template < typename valueType >
bool cLuaTable::isEntryPresent( std::string entryKey )
{
	if( returnComponentIndex< componentType >( entryKey ) == -1 )
	{
		return false
	}
	else
	{
		return true
	}
}

template < typename valueType >
bool cLuaTable::synchronizeEntry( cLuaTableEntryInterface< valueType >* entry )
{
	if( isEntryPresent( static_cast< cLuaTableEntry< valueType >* >( entry )->key ) )
	{
		table[ returnEntryIndex( static_cast< cLuaTableEntry< valueType >* >( entry )->key ) ]->value = static_cast< cLuaTableEntry< valueType >* >( entry )->value;
		return true; //true - element was changed
	}
	else
	{
		table.push_back( entry );
		return false; //false - element was added
	}
}

template < typename valueType >
bool cLuaTable::deleteEntry( std::string entryKey )
{
	if( not isEntryPresent( entryKey )
	{
		return false;
	}
	else
	{
		table.erase( returnEntryIndex( entryKey ) );
		return true;
	}
}

template < typename valueType >
valueType* cLuaTable::returnEntryValue( std::string entryKey )
{
	if( not isEntryPresent( entryKey ) )
	{
		return NULL;
	}
	else
	{
		return static_cast< cLuaTableEntry< valueType >* >( table[ returnEntryIndex( entryKey ) ] )->value;
	}
}

cLuaTable::cLuaTable( std::vector< std::unique_ptr< cLuaTableEntryInterface* > _table ) :
	table( _table )
{
	
}

/////////////////////////////////////////////////
//cLua

template < typename variableType >
variableType cLua::convertVariable( int index )
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
variableType cLua::getVariable( std::string variableName )
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

