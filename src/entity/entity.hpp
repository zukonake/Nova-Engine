//entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

#include "lua/luaTable.hpp"
#include "entitySubtype.hpp"
#include "entityControl.hpp"

class cEntity
{
	cBoard* board;
	cEntitySubtype* subtype;
	cEntityControl* control;
	cLuaTable componentList;
	uint16_t posX;
	uint16_t posY;
	std::string name;
	bool move( uint16_t targetPosX, uint16_t targetPosY );
	cEntity( cLuaTable luaToCpp );
	cEntity( std::string _name, cBoard _board, cLuaTable _componentList, uint16_t posX, uint16_t posY );
}

#endif
