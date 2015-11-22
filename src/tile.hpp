//tile.hpp
#ifndef TILE_HPP
#define TILE_HPP

#include <cstdin>
#include "typedef.hpp"
#include "interface.hpp"

class cTile
{
	friend class cBlock;
	char base;
	uint8_t foregroundColor;
	uint8_t backgroundColor;
public:
	void render( cInterface* interface, uint posX, uint posY );
	cTile( char _base, uint8_t _foregroundColor, uint8_t _backgroundColor);
};

#endif
