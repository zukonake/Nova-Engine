//block.hpp
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdin>
#include <string>

#include "tile.hpp"
#include "blockSubtype.hpp"

class cBlock
{
	friend class cBoard;
	cTile* tile;
	cBlockSubtype* blockSubtype;
	uint8_t height;
	cTile( cTile* _tile, cBlockSubtype* _blockSubtype, uint8_t _height )
}

#endif
