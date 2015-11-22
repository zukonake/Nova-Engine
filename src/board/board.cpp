//board.cpp
#include "board.hpp"

bool cBoard::canTeleport( uint posX, uint posY )
{
	if( posX < width && posX >= 0 && posY < height && posY >= 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}
