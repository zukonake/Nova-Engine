//board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>

#include <block.hpp>

class cBoard
{
	friend class cEntity;
	std::vector < cBlock* > blockList;
	std::string name;
	cBoard()
}

#endif
