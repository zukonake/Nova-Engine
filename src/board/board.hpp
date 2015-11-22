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
	std::vector < cBlock* > blockVector;
	cBoardGenerator* generator;
	std::string name;
	cBoard()
}

#endif
