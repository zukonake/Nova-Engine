//lua.hpp
#ifndef LUA_HPP
#define LUA_HPP

#include <string>

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

class cLuaTableEntryInterface
{
	//Interface
};

template < typename valueType >
class cLuaTableEntry : private cLuaTableEntryInterface
{
	friend class cLuaTable;
	protected:
	std::string key;
	valueType value;
	public:
	std::string returnKey();
	valueType returnValue();
	cComponent( std::string _key, valueType _value );
};

class cLuaTable
{
	protected:
	std::vector < std::unique_ptr< cLuaTableEntryInterface* > table;
	template < typename valueType >
	int16_t returnEntryIndex( std::string entryKey );
	public:
	template < typename valueType >
	bool synchronizeEntry( cLuaTableEntryi< valueType >* entry );
	template < typename valueType >
	bool isEntryPresent( std::string entryKey );
	template < typename valueType >
	bool deleteEntry( std::string entryKey );
	template < typename valueType >
	valueType* returnEntryValue( std::string entryKey );
	cLuaTable( std::vector< std::unique_ptr< cLuaTableEntryInterface* > _table );
	cLuaTable();
};

class cLua
{
	lua_state *L;
	std::string fileName;
	template < typename variableType >
	variableType convertVariable( int index );
	template < typename variableType >
	variableType getVariable( std::string variableName );
	template < typename variableType >
	variableType getTable( std::string tableName );
	template < typename variableType >
	variableType runFunction( std::string functionName );
	bool openScript( std::string fileName );
	cLua();
	~cLua();
}


#endif
