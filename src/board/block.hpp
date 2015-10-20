//block.hpp
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>
#include <string>

#include "tile.hpp"
#include "blockSubtype.hpp"

class cBlock
{
	friend class cBoard;
	cTile* tile;
	cBlockSubtype* subtype;
	uint8_t height;
	cBlock( cTile* _tile, cBlockSubtype* _subtype, uint8_t _height )
}

#endif
