//luaTable.hpp
#ifndef LUATABLE_HPP
#define LUATABLE_HPP

#include <string>
#include <vector>
#include <memory>
#include <cstdint>

class cLuaTableEntryInterface
{
	//Supposed to be blank
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

#endif
