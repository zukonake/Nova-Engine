#include "camera.hpp"

void cCamera::render( std::shared_ptr< cInterface > interface, cPosition screenPos, uint fov )
{
	for( uint iY = boardPos->y - fov; iY < boardPos->y + fov; iY++ )
	{
		for( uint iX = boardPos->x - fov; iX < boardPos->x + fov; iX++ )
		{
			std::shared_ptr< cBlock > block = board->getBlock( cPosition( iX, iY ) );
			if( block != std::shared_ptr< cBlock >() )
			{
				block->render( interface, screenPos );
			}
			else
			{
				throw "03"; //Non-existent block rendered;
			}
		}
	}
}

cCamera::cCamera( std::shared_ptr< cBoard > _board, std::shared_ptr< cPosition > _boardPos )
{
	if( _board != std::shared_ptr< cBoard >() )
	{
		if( _board->canTeleport( boardPos ) )
		{
			boardPos = _boardPos;
			board = _board;
		}
	}
	else
	{
		throw "01"; //Invalid board pointer.
	}
}

cCamera::cCamera( std::shared_ptr< cEntity > wrapTarget )
{
	if( wrapTarget != std::std::shared_ptr< cCamera >() )
	{
		boardPos = wrapTarget->getBoardPos();
		board = wrapTarget->getBoard();
	}
	else
	{
		throw "02"; //Invalid wrapTarget pointer.
	}
}
