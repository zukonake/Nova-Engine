//entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include "../typedef.hpp"
#include "../board.hpp"
#include "entitySubtype.hpp"
#include "entityControl.hpp"

class cEntity
{
	cBoard* board;
	cEntitySubtype* subtype;
	cEntityControl* control;
	std::string name;
	table componentTable;
	uint posX;
	uint posY;
	bool move( uint targetPosX, uint targetPosY );
	cEntity( table luaToCpp, table* objectTable );
	cEntity( std::string _name, cBoard _board, table _componentTable, uint _posX = 0, uint _posY = 0 );
};

#endif
