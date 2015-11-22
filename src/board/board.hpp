//board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>

#include "block.hpp"
#include "boardGenerator.hpp"

class cBoard
{
	friend class cEntity;
	std::vector < cBlock* > blockList;
	cBoardGenerator* generator;
	std::string name;
	uint height;
	uint width;
public:
	bool canTeleport( uint posX, uint posY );
	cBoard()
};

#endif
