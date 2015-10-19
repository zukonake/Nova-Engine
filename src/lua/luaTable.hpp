//luaTable.hpp
#ifndef LUATABLE_HPP
#define LUATABLE_HPP

#include <string>
#include <vector>
#include <memory>
#include <cstdint>

class cLuaEntryInterface
{
	//Supposed to be blank
};

template < typename valueType >
class cLuaEntry : private cLuaEntryInterface
{
	friend class cLuaTable;
	protected:
	valueType key;
	valueType value;
	public:
	std::string returnKey();
	valueType returnValue();
	cLuaEntry( std::string _key, valueType _value );
};

class cLuaTable
{
	protected:
	std::vector < std::unique_ptr< cLuaEntryInterface* > table;
	template < typename valueType >
	int16_t returnEntryIndex( std::string entryKey );
	public:
	template < typename valueType >
	bool set( cLuaTableEntry< valueType >* entry );
	template < typename valueType >
	bool is( std::string entryKey );
	template < typename valueType >
	bool remove( std::string entryKey );
	uint16_t size();
	template < typename valueType >
	valueType* value( std::string entryKey );
	cLuaTable( std::vector< std::unique_ptr< cLuaEntryInterface* > _table );
	cLuaTable();
};

#endif
