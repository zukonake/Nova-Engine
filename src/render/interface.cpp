//interface.cpp
#include "interface.hpp"

void cInterface::render( SDL_Renderer* renderer )
{
	SDL_RenderCopy( renderer, texture, NULL, NULL );
	for( auto iterator : componentVector )
	{
		componentVector[i]->render();
	}
}

cInterface::cInterface( table luaToCpp, table* objectList ) :
	componentTable( boost::any_cast< table >( luaToCpp["component"] ) ),
	posX( boost::any_cast< uint >( luaToCpp["posX"] ) ),
	posY( boost::any_cast< uint >( luaToCpp["posY"] ) ),
	width( boost::any_cast< uint >( luaToCpp["width"] ) ),
	height( boost::any_cast< uint >( luaToCpp["height"] ) ),
	window( newwin( height, width, posY, posX ) ),
	hBorder( boost::any_cast< char >( luaToCpp["hBorder"] ) ),
	vBorder( boost::any_cast< char >( luaToCpp["vBorder"] ) )
{

}

cInterface::cInterface( table _componentTable, uint _posX, uint _posY, uint _width, uint _height, char _hBorder, char _vBorder ) :
	componentTable( _componentTable ),
	posX( _posX ),
	posY( _posY ),
	width( _width ),
	height( _height ),
	nCursesWindow( newwin( height, width, posY, posX ),
	hBorder( _hBorder ),
	vBorder( _vBorder )
{

}

cInterface::~cInterface()
{
	delwin( nCursesWindow );
}
