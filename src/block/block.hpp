//block.hpp
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>
#include <string>

#include "typedef.hpp"
#include "interface.hpp"
#include "tile.hpp"
#include "blockSubtype.hpp"

class cBlock
{
	friend class cBoard;
	cTile* tile;
	cBlockSubtype* subtype;
	uint8_t height;
	void render( cInterface* interface, uint posX, uint posX );
	cBlock( cTile* _tile, cBlockSubtype* _subtype, uint8_t _height );
};

#endif
