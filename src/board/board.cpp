//board.cpp
#include <boost/any.hpp>
//
#include "board.hpp"

bool cBoard::canTeleport( const cPosition& targetPos )
{
	if( targetPos.x < width && targetPos.x >= 0 && targetPos.y < height && targetPos.y >= 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::shared_ptr< cBlock > cBoard::getBlock( cPosition targetPosition )
{
	cassert( targetPosition.x < width && targetPosition.x >= 0 );
	cassert( targetPosition.y < height && targetPosition.y >= 0 );
	return blocks[ targetPosition.x ][ targetPosition.y ];
}

cBoard::cBoard( blockVector _blocks, std::shared_ptr< cBoardGenerator > _generator, std::string _name, uint _height, uint _width) :
	blocks( _blocks ),
	generator( _generator ),
	name( _name ),
	height( _height ),
	width( _width )
{

}

cBoard::cBoard( table luaToCpp, std::shared_ptr< table > objectTable ) :
	blockVector( boost::any_cast< blockVector >( luaToCpp[ "blockVector" ] )),
	generator( boost::any_cast< std::shared_ptr< cBoardGenerator > >( luaToCpp[ "generator" ] )),
	name( boost::any_cast< std::string >( luaToCpp[ "name" ] )),
	height( boost::any_cast< uint >( luaToCpp[ "height" ] )),
	width( boost::any_cast< uint >( luaToCpp[ "width" ] ))
{

}
