//entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <memory>
//
#include <typedef.hpp>
#include <board/board.hpp>
#include <entity/entitySubtype.hpp>
#include <entity/entityControl.hpp>

class cEntity
{
	std::shared_ptr< cBoard* > board;
	cPosition boardPos;
	cEntitySubtype* subtype;
	cEntityControl* control;
	table componentTable;

	bool move( uint targetPosX, uint targetPosY );
public:
	std::shared_ptr< cPosition > getBoardPos();
	std::shared_ptr< cBoard > getBoard();
private:
	cEntity( table luaToCpp, table* objectTable );
	cEntity( std::string _name, cBoard _board, table _componentTable, uint _posX = 0, uint _posY = 0 );
};

#endif
