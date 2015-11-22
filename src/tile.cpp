//tile.cpp
#include "tile.hpp"

void cTile::render( WINDOW* nCursesWindow, uint posX, uint posY )
{
	// TODO colors
	mvprintw( nCursesWindow, posX, posY, base );
}

cTile::cTile( char _base, uint _foregroundColor, uint _backgroundColor ) :
	base( _base ),
	foregroundColor( _foregroundColor ),
	backgroundColor( _backgroundColor )
{

}
