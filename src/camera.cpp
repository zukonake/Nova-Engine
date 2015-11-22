#include "camera.hpp"

bool cCamera::move( uint _posX, uint _posY, cBoard* _board )
{
	if( _board->canMove( _posX, _posY ) )
	{
		posX = _posX;
		posY = _posY;
		board = _board;
		return true;
	}
	else
	{
		return false;
	}
}

void cCamera::render( cInterface* interface, uint fov, uint posX, uint posY )
{
	for( uint iY = posY - fov; iY < posY + fov; iY++ )
	{
		for( uint iX = posX - fov; iX < posX + fov; iX++ )
		{
			board->blockArray[iX][iY]->render( interface, posX + iX, posY + iY );
		}
	}
}

cCamera::cCamera( uint _posX, uint _posY, cBoard* _board ) :
	posX( _posX ),
	posY( _posY ),
	board( _board )
{

}
