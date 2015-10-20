//tile.hpp
#ifndef TILE_HPP
#define TILE_HPP

#include <cstdin>

class cTile
{
	friend class cBlock;
	char base;
	uint8_t foregroundColor;
	uint8_t backgroundColor;
	cTile( char _base, uint8_t _foregroundColor, uint8_t _backgroundColor);
}

#endif
