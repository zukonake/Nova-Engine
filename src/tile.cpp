//tile.cpp
#include "tile.hpp"

void cTile::render( cInterface* interface, uint posX, uint posY )
{
	//TODO colors
	mvwprintw( interface->nCursesWindow, posX, posY, base, "%c");
}

cTile::cTile( char _base, uint8_t _foregroundColor, uint8_t _backgroundColor ) :
	base( _base ),
	foregroundColor( _foregroundColor ),
	backgroundColor( _backgroundColor )
{

}
