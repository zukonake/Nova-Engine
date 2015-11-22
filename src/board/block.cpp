//block.cpp
#include "block.hpp"

void cBlock::render( cInterface* interface, uint posX, uint posY )
{
	tile->render( interface, posX, posY );
}

cBlock( cTile* _tile, cBlockSubtype* _subtype, uint8_t _height ) :
	tile( _tile ),
	subtype( _subtype ),
	height( _height )
{

}
