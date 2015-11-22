//tile.hpp
#ifndef TILE_HPP
#define TILE_HPP

#include <ncurses.h>
#include "typedef.hpp"

class cTile
{
	char base;
	uint foregroundColor;
	uint backgroundColor;
	void render( WINDOW* nCursesWindow, uint posX, uint posY );
	cTile( char _base, uint _foregroundColor, uint _backgroundColor);
}

#endif
