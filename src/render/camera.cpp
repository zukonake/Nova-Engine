#include "camera.hpp"

void cCamera::render( cInterface* interface, cPosition screenPos, uint fov )
{
	for( uint iY = boardPos.y - fov; iY < boardPos.y + fov; iY++ )
	{
		for( uint iX = boardPos.x - fov; iX < boardPos.x + fov; iX++ )
		{
			std::shared_ptr< cBlock > block = board->getBlock( cPosition( iX, iY ) );
			block->render( interface, screenPos );
		}
	}
}

cCamera::cCamera( std::shared_ptr< cBoard > _board, cPosition _boardPos )
{
	if( _board != std::nullptr )
	{
		if( _board->canTeleport( boardPos ) )
		{
			boardPos = _boardPos;
			board = _board;
		}
	}
	else
	{
		throw 01; //Invalid board pointer.
	}
}
