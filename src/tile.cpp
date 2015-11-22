//tile.cpp
#include "tile.hpp"

void cTile::render( cInterface* interface, uint posX, uint posY )
{
	//TODO colors
	if( bold )
	{
		attron( A_BOLD );
	}
	mvwprintw( interface->nCursesWindow, posX, posY, base, "%c");
	attroff( A_BOLD );
}

cTile::cTile( char _base, uint8_t _foregroundColor, uint8_t _backgroundColor, bool _bold ) :
	base( _base ),
	foregroundColor( _foregroundColor ),
	backgroundColor( _backgroundColor )
{

}
