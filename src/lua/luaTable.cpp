//luaTable.cpp
#include "luaTable.hpp"

//cLuaEntry

template < typename valueType >
valueType cLuaEntry::returnValue()
{
	return ( valueType )value;
}

std::string cLuaEntry::returnKey()
{
	return key;
}

template < typename valueType >
cLuaTableEntry::cLuaEntry( std:string _key, valueType _value )
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
		if( static_cast< cLuaEntry< valueType >* >( table[i] )->key == entryKey )
		{
			return i;
		}
	}
	return -1;
}

template < typename valueType >
bool cLuaTable::is( std::string entryKey )
{
	if( returnEntryIndex< componentType >( entryKey ) == -1 )
	{
		return false
	}
	else
	{
		return true
	}
}

template < typename valueType >
bool cLuaTable::set( cLuaEntryInterface< valueType >* entry )
{
	if( isEntryPresent( static_cast< cLuaEntry< valueType >* >( entry )->key ) )
	{
		table[ returnEntryIndex( static_cast< cLuaEntry< valueType >* >( entry )->key ) ]->value = static_cast< cLuaEntry< valueType >* >( entry )->value;
		return true; //true - element was changed
	}
	else
	{
		table.push_back( entry );
		return false; //false - element was added
	}
}

template < typename valueType >
bool cLuaTable::remove( std::string entryKey )
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

uint16_t cLuaTable::size()
{
	return ( uint16_t )table.size();
}

template < typename valueType >
valueType* cLuaTable::value( std::string entryKey )
{
	if( not isEntryPresent( entryKey ) )
	{
		return NULL;
	}
	else
	{
		return static_cast< cLuaEntry< valueType >* >( table[ returnEntryIndex( entryKey ) ] )->value;
	}
}

cLuaTable::cLuaTable( std::vector< std::unique_ptr< cLuaEntryInterface* > _table ) :
	table( _table )
{
	
}
