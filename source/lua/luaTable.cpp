//luaTable.cpp
#include "luaTable.hpp"

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
