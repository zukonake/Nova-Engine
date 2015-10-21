//interface.cpp
#include "interface.hpp"

void cInterface::print()
{
	box( nCursesWindow, hBorder, vBorder );
	//print teh stuff
	wrefresh( nCursesWindow );
}

void cInterface::clear()
{
	wclear( nCursesWindow );
}
/* not sure if needed
void cInterface::refresh()
{
	wrefresh( nCursesWindow );
}
*/
cInterface::cInterface( cLuaTable _componentList, std::string _name, uint16_t _posX, uint16_t _posY, uint16_t _width, uint16_t _height, char _hBorder, char _vBorder ) :
	componentList( _componentList ),
	name( _name ),
	posX( _posX ),
	posY( _posY ),
	width( _width ),
	height( _height ),
	hBorder( _hBorder ),
	vBorder( _vBorder )
{
	nCursesWindow = newwin( height, width, posY, posX );
}

cInterface::~cInterface()
{
	delwin( nCursesWindow );
}
