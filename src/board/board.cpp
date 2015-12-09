//board.cpp
#include "board.hpp"
#include <boost/any.hpp>

bool cBoard::canTeleport( cPosition targetPos )
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

cBoard::cBoard( std::vector< cBlock* > _blockVector, cBoardGenerator* _generator, std::string _name, uint _height, uint _width) :
	blockVector( _blockVector ),
	generator( _generator ),
	name( _name ),
	height( _height ),
	width( _width )
{

}

cBoard::cBoard( table luaToCpp, table* objectTable ) :
	blockVector( boost::any_cast< std::vector< cBlock* > >( luaToCpp[ "blockVector" ] )),
	generator( boost::any_cast< cBoardGenerator* >( luaToCpp[ "generator" ] )),
	name( boost::any_cast< std::string >( luaToCpp[ "name" ] )),
	height( boost::any_cast< uint >( luaToCpp[ "height" ] )),
	width( boost::any_cast< uint >( luaToCpp[ "width" ] ))
{

}
