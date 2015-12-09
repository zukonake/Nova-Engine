//board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>
//
#include <typedef.hpp>
#include <position.hpp>
#include <block/block.hpp>
#include <board/boardGenerator.hpp>

class cBoard
{
	friend class cEntity;
	friend class cGame::initializeObjects();
	std::vector < cBlock* > blockVector;
	cBoardGenerator* generator;
	std::string name;
	uint height;
	uint width;
public:
	bool canTeleport( cPosition targetPos );
private:
	cBoard( std::vector< cBlock* > _blockVector, cBoardGenerator* _generator, std::string _name, uint _height, uint _width);
	cBoard( table luaToCpp, table* objectTable );
};

#endif
